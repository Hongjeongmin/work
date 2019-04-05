# Lab 5 Logistic Regression Classifier
import tensorflow as tf
tf.set_random_seed(777)  # for reproducibility

x_data = [[1, 2],
          [2, 3],
          [3, 1],
          [4, 3],
          [5, 3],
          [6, 2]]
y_data = [[0],
          [0],
          [0],
          [1],
          [1],
          [1]]
#x1,x2 6개가 주어진다 y는 바이너리로 주어진다
# placeholders for a tensor that will be always fed.
# 0fail 1 pass
X = tf.placeholder(tf.float32, shape=[None, 2])# x1, x2니깐 none은 몇개받을지모르니깐
Y = tf.placeholder(tf.float32, shape=[None, 1])# y는 하나밖에 없으니깐 1이다

W = tf.Variable(tf.random_normal([2, 1]), name='weight')
b = tf.Variable(tf.random_normal([1]), name='bias')

# Hypothesis using sigmoid: tf.div(1., 1. + tf.exp(tf.matmul(X, W)))
hypothesis = tf.sigmoid(tf.matmul(X, W) + b)#바이너리한값 추측할때는 e^z 를 표현해야하므로 sigmoid라는 함수에 넣어준다.

# cost/loss function
cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) *
                       tf.log(1 - hypothesis))
                       #cost는 log함수를 치한데 리니얼을 적용하면 이상하게 나와서~ 0일때 1일때 경우를 따져서 계산

train = tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(cost)
#train 이 알아서 cost를 미니마이즈해준다
# Accuracy computation
# True if hypothesis>0.5 else False
predicted = tf.cast(hypothesis > 0.5, dtype=tf.float32)#true=1 false =0 dtype 캐스팅하게되면 알아서나옴
accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted, Y), dtype=tf.float32))

# Launch graph
with tf.Session() as sess:
    # Initialize TensorFlow variables
    sess.run(tf.global_variables_initializer())

    for step in range(10001):
        cost_val, _ = sess.run([cost, train], feed_dict={X: x_data, Y: y_data})
        if step % 200 == 0:
            print(step, cost_val)

    # Accuracy report
    h, c, a = sess.run([hypothesis, predicted, accuracy],
                       feed_dict={X: x_data, Y: y_data})
    print("\nHypothesis: ", h, "\nCorrect (Y): ", c, "\nAccuracy: ", a)

'''
0 1.73078
200 0.571512
400 0.507414
600 0.471824
800 0.447585
...
9200 0.159066
9400 0.15656
9600 0.154132
9800 0.151778
10000 0.149496

Hypothesis:  [[ 0.03074029]
 [ 0.15884677]
 [ 0.30486736]
 [ 0.78138196]
 [ 0.93957496]
 [ 0.98016882]]
Correct (Y):  [[ 0.]
 [ 0.]
 [ 0.]
 [ 1.]
 [ 1.]
 [ 1.]]
Accuracy:  1.0
'''
