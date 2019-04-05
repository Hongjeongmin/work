# Lab 3 Minimizing Cost
import tensorflow as tf
tf.set_random_seed(777)  # for reproducibility

x_data = [1, 2, 3]
y_data = [1, 2, 3]

# Try to find values for W and b to compute y_data = W * x_data + b
# We know that W should be 1 and b should be 0
# But let's use TensorFlow to figure it out
W = tf.Variable(tf.random_normal([1]), name='weight')
#random_nrmal 값을 줫어~
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

# Our hypothesis for linear model X * W
hypothesis = X * W

# cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# Minimize: Gradient Descent using derivative: W -= learning_rate * derivative
learning_rate = 0.1
# 학습 rate~ 이라고 한다
gradient = tf.reduce_mean((W * X - Y) * X)
#(W * X - Y) * X 는 미분한 값임 이값들을 평균내줌 reduce_mean이라는 함수로~
descent = W - learning_rate * gradient
#현재의 W값에 오차가없는 방향으로 가는 값으로 값을 조정해준다. descent = new W 가된다
update = W.assign(descent)
# 텐서플로우는 w = w - 이렇게 못해서 assign이라는 함수를 쓴다
# assign하는 동작을 updae라는것으로 가져왓음 따라서 update 실행 하면 위의 과정이 다됨

# Launch the graph in a session.
sess = tf.Session()
# Initializes global variables in the graph.
sess.run(tf.global_variables_initializer())

for step in range(21):
    sess.run(update, feed_dict={X: x_data, Y: y_data})
    print(step, sess.run(cost, feed_dict={X: x_data, Y: y_data}), sess.run(W))

'''
0 1.93919 [ 1.64462376]
1 0.551591 [ 1.34379935]
2 0.156897 [ 1.18335962]
3 0.0446285 [ 1.09779179]
4 0.0126943 [ 1.05215561]
5 0.00361082 [ 1.0278163]
6 0.00102708 [ 1.01483536]
7 0.000292144 [ 1.00791216]
8 8.30968e-05 [ 1.00421977]
9 2.36361e-05 [ 1.00225055]
10 6.72385e-06 [ 1.00120032]
11 1.91239e-06 [ 1.00064015]
12 5.43968e-07 [ 1.00034142]
13 1.54591e-07 [ 1.00018203]
14 4.39416e-08 [ 1.00009704]
15 1.24913e-08 [ 1.00005174]
16 3.5322e-09 [ 1.00002754]
17 9.99824e-10 [ 1.00001466]
18 2.88878e-10 [ 1.00000787]
19 8.02487e-11 [ 1.00000417]
20 2.34053e-11 [ 1.00000226]
'''
