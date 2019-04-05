# Lab 3 Minimizing Cost
import tensorflow as tf
tf.set_random_seed(777)  # for reproducibility

# tf Graph Input
X = [1, 2, 3]
Y = [1, 2, 3]

# Set wrong model weights
W = tf.Variable(5.0)

# Linear model
hypothesis = X * W

# cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# Minimize: Gradient Descent Magic
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1)#식을 세우고
train = optimizer.minimize(cost)#그식을 계산해라
#자동으로 cost를 minimize해준다~
#미분값을 일일이 미분하면서 구할필요가없다 이렇게하면된다!
# 03-02에 있던 그래디언트구해서 W'= w- 0.1 미분값 이것을 자동화해줌~

# Launch the graph in a session.
sess = tf.Session()
# Initializes global variables in the graph.
sess.run(tf.global_variables_initializer())

for step in range(100):
    print(step, sess.run(W))
    sess.run(train)

'''
0 5.0
1 1.26667
2 1.01778
3 1.00119
4 1.00008
...
96 1.0
97 1.0
98 1.0
99 1.0
'''
