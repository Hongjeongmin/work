# 수정 및 주석 : webnautes







from __future__ import print_function

import tensorflow as tf
import numpy       # 파이썬 리스트로 제공되는 입력을 NumPy 배열로 바꾸기 위해 사용됩니다.
import matplotlib.pyplot as plt   # 그래프를 그리기 위해 사용됩니다.




# 훈련시킬 때 사용되는 파라미터
learning_rate = 0.01     # GradientDescentOptimizer에 적용할 학습률입니다. 너무 크거나 작으면 훈련결과가 좋지 않게 됩니다.
training_epochs = 1000   # 전체 반복하는 훈련 횟수입니다. 보통 1000번 훈련을 반복시킵니다.
display_step = 50        # 훈련 도중 중간 결과로 비용(cost)와 모델의 파라미터(W, b)를 출력할 간격입니다.



# 훈련 데이터(Training Data)
train_X = numpy.asarray([3.3,4.4,5.5,6.71,6.93,4.168,9.779,6.182,7.59,2.167,   # numpy.asarray 리스트를 배열로 변환합니다.
                         7.042,10.791,5.313,7.997,5.654,9.27,3.1])
train_Y = numpy.asarray([1.7,2.76,2.09,3.19,1.694,1.573,3.366,2.596,2.53,1.221,
                         2.827,3.465,1.65,2.904,2.42,2.94,1.3])
num_of_samples = train_X.shape[0]


# 모델의 입력을 플레이스홀더로 정의합니다.   ---> 모델의 입력으로 플레이스 홀더를 사용합니다.
X = tf.placeholder(tf.float32)  # tf.float32 대신에 "float"를 사용하기도 합니다.
Y = tf.placeholder(tf.float32)

# 모델의 출력을 결정하는 모델 파라미터는 다음 두가지 입니다.   --> 모델의 파라미터로 변수를 사용합니다.
# 변수에 값이 지정되어 있지만 나중에 초기화를 해주어야 해당 값으로 변수가 초기화됩니다.
# 여기에선 numpy.random.randn()를 사용하여 랜덤으로 숫자를 발생시켜 초기값으로 사용합니다. 초기값이 결과에 큰 영향을 주지않기 때문에 랜덤값을 사용합니다.
W = tf.Variable(numpy.random.randn(), name="weight")
b = tf.Variable(numpy.random.randn(), name="bias")

# 선형 모델(linear model)을 정의합니다. 여기에서 X는 플레이스홀더이기 때문에 모델을 계산하려면 나중에 X에 데이터를 제공해줘야 합니다.
pred = tf.add(tf.multiply(X, W), b)   # pred = X * W + b

# 평균 제곱 오차 MSE(Mean Squared Error)를 모델 성능 측정에 사용합니다.
# 모델에서 입력 X로부터 계산된 값 pred와 입력 X와 함께 제공된 Y가 얼마나 차이있는지 측정합니다.
cost = tf.reduce_sum(tf.pow(pred-Y, 2))/(2*num_of_samples)


# 경사 하강법(Gradient descent)으로 비용(cost)를 최소화(minimize)하는 모델 파라미터 W와 b를 찾습니다.
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)


# 세션에서 실행시켜야 훈련이 시작됩니다.
with tf.Session() as sess:

    # 변수 W와 b가 앞에서 지정한 값으로 초기화됩니다.
    sess.run(tf.global_variables_initializer())

    # Fit all training data --> fiting은 모든 훈련 데이터에 맞도록 모델의 파라미터를 수정하는 과정입니다.
    for epoch in range(training_epochs):
        for (x, y) in zip(train_X, train_Y):   # zip에 있는 리스트들을 원소로하는 튜플을 생성하여
            sess.run(optimizer, feed_dict={X: x, Y: y})  # 모델의 입력인 플레이스홀더 X, Y에 데이터로 제공합니다. 그래야 optimizer를 실행할 수 있습니다.

        # 앞에서 지정한 display_step 마다 중간 결과를 출력합니다.
        if (epoch+1) % display_step == 0:
            c = sess.run(cost, feed_dict={X: train_X, Y:train_Y})
            print("Epoch:", '%04d' % (epoch+1), "cost=", "{:.9f}".format(c), \
                "W=", sess.run(W), "b=", sess.run(b))


    print("최적화가 완료되었습니다.")
    training_cost = sess.run(cost, feed_dict={X: train_X, Y: train_Y})
    print("훈련이 끝난 후 비용과 모델 파라미터입니다.  cost=", training_cost, "W=", sess.run(W), "b=", sess.run(b), '\n')

    # 훈련에 사용했던 데이터를 화면에 점으로 표현하고 훈련 마친 모델이 어떻게 그려지는지 보여줍니다.
    plt.plot(train_X, train_Y, 'ro', label='Original data')            # 훈련 데이터를 점으로 표현합니다.ㅏ
    plt.plot(train_X, sess.run(W) * train_X + sess.run(b), label='Fitted line')  # 최종 결정된 모델 파라미터를 직선으로 표현합니다.
    plt.legend()  # plt.plot를 호출하면서 lable 아규먼트로 지정한 도표 설명을 화면에 보여줍니다.
    plt.show()
