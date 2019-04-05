x_train = [1,2,3];
y_train = [1,2,3];
# how Wx + b
W = tf.Variable(tf.random_normal([1]), name='weight')
b = tf.Variable(tf.random_normal([1]), name='bias')
# 초기 W와 b값을 모르기 때문에 random 하게 준다~
hypothesis = x_train * w + b
#hypothesis 는 가설 이라는 뜻
cost = tf.reduce_mean(tf.square(hypothesis - y_train))
# cost 는 실제값과 추측값의 즉 오차의 평균이라고 생각하자!
# squre는 차의 제곱을 해주는거 같오~

t = [1., 2., 3.,4.]
tf.reduce_mean(t) #====> 2.5 tensorflow 에서 평균내주는 함수~

#Minimize
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train = optimizer.minimize(cost)
#W와 B를 조작해서 미니마이즈 한다~
#train 은 cost를 미니마이즈를해라~
#optimizer : 최대한 활용하는 사람
###################################################################
sess = tf.Session()

sess.run(tf.global_variables_initializer())
#텐서플로우의 W와 b를 사용하기 전에는 위의 코드를 반드시 실행해줘야한다~
for step in range(2001);
    sess.run(train)
    if step % 20 == 0:
        print(step, sess.run(cost), sess.run(W),sess.run(b))
###############################################


X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

for step in range(2001):
    cost_Val, W_val, b_val, _ = \
        sess.run([cost, W, b, train],
                feed_dict={X: [1,2,3], Y:[1,2,3]})
        if step % 20 == 0:
            print(step, cost_val, W_val, b_val)
# cost W b train 을 리스트에 넣어서 넘겨줄수있고 그때마다 필요한값은 feed_dict로 받는다.
