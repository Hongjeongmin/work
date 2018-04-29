import tensorflow as tf

x_train = [1, 2, 3]
y_train = [1, 2, 3]

w = tf.Variable(tf.random_normal([1]), name='weight')
b = tf.Variable(tf.random_normal([1]), name ='bias')
# Our hypothesis XW+b
hypothesis = x_train * w + b

# cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - y_train))

# Minimize
learning_rate = 0.01
optimizer = tf.train.GradientDescentOptimizer(learning_rate)
train = optimizer.minimize(cost)

# Launch the groph in a session.
sess= tf.Session()
# Initializes global variables in the graph.
sess.run(tf.global_variables_initializer())

# Fit the Line
for step in range(2001):
    sess.run(train)
    if step & 20 ==0:
        print(step, sess.run(cost), sess.run(w), sess.run(b))
