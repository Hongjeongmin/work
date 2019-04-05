# Lab 3 Minimizing Cost
import tensorflow as tf
import matplotlib.pyplot as plt
#없으면 설치하자~ 먼가 매트랩 함수인거같네
tf.set_random_seed(777)  # for reproducibility

X = [1, 2, 3]
Y = [1, 2, 3]

W = tf.placeholder(tf.float32)

# Our hypothesis for linear model X * W
hypothesis = X * W

# cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# Launch the graph in a session.
sess = tf.Session()
#그래프를 구성하기위해서 session 을 열자

# Variables for plotting cost function
W_history = [] # 저장할 리스트를 만들자
cost_history = [] #저장할 리스트를 만들자

for i in range(-30, 50):
    curr_W = i * 0.1
    curr_cost = sess.run(cost, feed_dict={W: curr_W})
    W_history.append(curr_W)
    cost_history.append(curr_cost)

# Show the cost function
plt.plot(W_history, cost_history)
plt.show()
