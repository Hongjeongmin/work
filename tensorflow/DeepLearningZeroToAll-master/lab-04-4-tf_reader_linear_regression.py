# Lab 4 Multi-variable linear regression
# https://www.tensorflow.org/programmers_guide/reading_data

import tensorflow as tf
tf.set_random_seed(777)  # for reproducibility 재생력 복사가능성?

filename_queue = tf.train.string_input_producer(
    ['data-01-test-score.csv'], shuffle=False, name='filename_queue')
#지금은 한갠데 파일을 한번에 리스트로 여러개 줄수있다. ['txt1','txt2','txt3']
#섞을건가? 이름은 변수이름이랑 동일하게 하는건듯
reader = tf.TextLineReader()#불러온파일을 읽을놈인데 txt형식으로 읽어온다. 밑에거랑 하나로 합쳐도될듯?
key, value = reader.read(filename_queue) # key value를 나눠서 읽겠다.

# Default values, in case of empty columns. Also specifies the type of the
# decoded result.
record_defaults = [[0.], [0.], [0.], [0.]]
xy = tf.decode_csv(value, record_defaults=record_defaults)
#value 갑을 어떻게 이해할거냐?  record_defaults로 어떤 데이타타입인지 없으면 0으로 주기도함

# collect batches of csv in
train_x_batch, train_y_batch = \
    tf.train.batch([xy[0:-1], xy[-1:]], batch_size=10)#size가 10인걸 알기 때문에 열만 0:-1 x1~x3 -1:   --> y 값 이렇게 출력됨
    #batch는 일조으이 범퍼같은역할?? x데이터 y데이터를 가져온다 한번에 10개씩

# placeholders for a tensor that will be always fed.
X = tf.placeholder(tf.float32, shape=[None, 3])
Y = tf.placeholder(tf.float32, shape=[None, 1])

W = tf.Variable(tf.random_normal([3, 1]), name='weight')
b = tf.Variable(tf.random_normal([1]), name='bias')

# Hypothesis
hypothesis = tf.matmul(X, W) + b

# Simplified cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# Minimize
optimizer = tf.train.GradientDescentOptimizer(learning_rate=1e-5)
train = optimizer.minimize(cost)

# Launch the graph in a session.
sess = tf.Session()
# Initializes global variables in the graph.
sess.run(tf.global_variables_initializer())

# Start populating the filename queue.
coord = tf.train.Coordinator()
threads = tf.train.start_queue_runners(sess=sess, coord=coord)

for step in range(2001):
    x_batch, y_batch = sess.run([train_x_batch, train_y_batch])#펌프질을해서 가져옴
    cost_val, hy_val, _ = sess.run(
        [cost, hypothesis, train], feed_dict={X: x_batch, Y: y_batch})
    if step % 10 == 0:
        print(step, "Cost: ", cost_val, "\nPrediction:\n", hy_val)

coord.request_stop()
coord.join(threads)

# Ask my score
print("Your score will be ",
      sess.run(hypothesis, feed_dict={X: [[100, 70, 101]]}))

print("Other scores will be ",
      sess.run(hypothesis, feed_dict={X: [[60, 70, 110], [90, 100, 80]]}))

'''
Your score will be  [[ 177.78144836]]
Other scores will be  [[ 141.10997009]
 [ 191.17378235]]

'''
