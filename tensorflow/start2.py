import tensorflow as tf

x = tf.placeholder(tf.float32, shape=[None])
y = tf.placeholder(tf.float32, shape=[None])
w = tf.Variable(tf.random_normal([1]), name='weight')
b = tf.Variable(tf.random_normal([1]), name ='bias')
# Our hypothesis XW+b
hypothesis = x * w + b

# cost/loss function
cost = tf.reduce_mean(tf.square(hypothesis - y))

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
    cost_val, w_val, v_val, _ = sess.run([cost, w, b, train],
    feed_dict = {x: [1, 2, 3, 4, 5],
                 y: [2.1, 3.1, 4.1, 5.1, 6.1]})
    if step & 20 ==0:
        print(step, cost_val, w_val, v_val)
