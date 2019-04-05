# Lab 6 Softmax Classifier
#SOFTMAX란것은 어떤 N개의 리니어한 값들을 각각의 확률나오게 해준다 (이런입력일때 이값일 확률~)
#어찌보면 binary도 2개의 리니어한 값의 확률로 만들어주는것인듯~
#각각의 n의 확률 다합치면 1된다.
import tensorflow as tf
tf.set_random_seed(777)  # for reproducibility

x_data = [[1, 2, 1, 1],
          [2, 1, 3, 2],
          [3, 1, 3, 4],
          [4, 1, 5, 5],
          [1, 7, 5, 5],
          [1, 2, 5, 6],
          [1, 6, 6, 6],
          [1, 7, 7, 7]]
y_data = [[0, 0, 1],#2
          [0, 0, 1],#2
          [0, 0, 1],#2
          [0, 1, 0],#1
          [0, 1, 0],#1
          [0, 1, 0],#1
          [1, 0, 0],#0
          [1, 0, 0]]#0
#one hot encoding레이블이다 하나만 핫하다 ㅎㅎㅎㅎㅎ 그런뜻인듯.. hot==1
X = tf.placeholder("float", [None, 4])
Y = tf.placeholder("float", [None, 3])
nb_classes = 3

W = tf.Variable(tf.random_normal([4, nb_classes]), name='weight')
b = tf.Variable(tf.random_normal([nb_classes]), name='bias')

# tf.nn.softmax computes softmax activations
# softmax = exp(logits) / reduce_sum(exp(logits), dim)
hypothesis = tf.nn.softmax(tf.matmul(X, W) + b)#softmax 라이브러리~

# Cross entropy cost/loss
cost = tf.reduce_mean(-tf.reduce_sum(Y * tf.log(hypothesis), axis=1))
#loss fuction

optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)
#미니마이즈 한다~

# Launch graph
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for step in range(2001):
        sess.run(optimizer, feed_dict={X: x_data, Y: y_data})
        if step % 200 == 0:
            print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}))

    print('--------------')

    # Testing & One-hot encoding
    a = sess.run(hypothesis, feed_dict={X: [[1, 11, 7, 9]]})
    print(a, sess.run(tf.argmax(a, 1)))# hypothesis의 확률을 보고 몇번째으 array가 가장큰값인지 출력

    print('--------------')

    b = sess.run(hypothesis, feed_dict={X: [[1, 3, 4, 3]]})
    print(b, sess.run(tf.argmax(b, 1)))

    print('--------------')

    c = sess.run(hypothesis, feed_dict={X: [[1, 1, 0, 1]]})
    print(c, sess.run(tf.argmax(c, 1)))

    print('--------------')

    all = sess.run(hypothesis, feed_dict={
                   X: [[1, 11, 7, 9], [1, 3, 4, 3], [1, 1, 0, 1]]})
    print(all, sess.run(tf.argmax(all, 1)))

'''
--------------
[[  1.38904958e-03   9.98601854e-01   9.06129117e-06]] [1]
--------------
[[ 0.93119204  0.06290206  0.0059059 ]] [0]
--------------
[[  1.27327668e-08   3.34112905e-04   9.99665856e-01]] [2]
--------------
[[  1.38904958e-03   9.98601854e-01   9.06129117e-06]
 [  9.31192040e-01   6.29020557e-02   5.90589503e-03]
 [  1.27327668e-08   3.34112905e-04   9.99665856e-01]] [1 0 2]
'''
