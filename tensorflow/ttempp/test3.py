# 수정 및 주석 : webnautes



import tensorflow as tf




#---------------------------------------------------------------------------------------------------- 1. MNIST 데이터를 가져옵니다.
# MNIST 데이터 관련 내용은 다음 포스팅 참고
#
# Tensorflow 예제 - MNIST 데이터 출력해보기 ( http://webnautes.tistory.com/1232 )
from tensorflow.examples.tutorials.mnist import input_data

# one_hot을 True로 설정하면 라벨을 one hot 벡터로 합니다. False이면 정수형 숫자가 라벨이 됩니다.
# /tmp/data/ 폴더를 생성하고 MNIST 데이터 압축파일을 다운로드 받아 압축을 풀고 데이터를 읽어옵니다.
# 이후에는 다운로드 되어있는 압축파일의 압축을 풀어서 데이터를 읽어옵니다.
mnist = input_data.read_data_sets("/tmp/data/", one_hot=True)



#---------------------------------------------------------------------------------------------------- 2. 모델을 생성합니다.
# 모델의 입력을 받기 위해 플레이스홀더를 사용합니다.
# 첫번째 차원이 None인 이유는 데이터 개수 제약없이 입력 받기 위해서입니다.
# 두번째 차원이 784인 것은  MNIST의 이미지의 크기가 28 x 28 = 784 픽셀이기 때문입니다.
x = tf.placeholder(tf.float32, [None, 784])

# 모델 파라미터
W = tf.Variable(tf.zeros([784, 10]))
b = tf.Variable(tf.zeros([10]))

# softmax를 사용한 모델을 생성
# W, b 모델 파라미터 -> 변수
# x 이미지 데이터 입력 -> 플레이스홀더
y_model = tf.matmul(x, W) + b



#---------------------------------------------------------------------------------------------------- 3. loss와 optimizer를 정의합니다.
y = tf.placeholder(tf.float32, [None, 10])  # 크기 10인 MNIST의 라벨 데이터

# 크로스 엔트로피(cross entropy) 함수 공식을 그대로 사용하면 수치적으로 불안정하여 계산 오류가 발생할 수 있습니다.
# cost = tf.reduce_mean(-tf.reduce_sum(y*tf.log(tf.nn.softmax(y_model)), reduction_indices=1))
#
# 그래서 tf.nn.softmax_cross_entropy_with_logits_v2를 사용합니다. (tf.nn.softmax_cross_entropy_with_logits는 deprecated 되었습니다.)

# cross entropy를 손실 함수(cost function)로 사용
#cost = tf.reduce_mean(-tf.reduce_sum(y*tf.log(tf.nn.softmax(y_model)), reduction_indices=1))
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(labels=y, logits=y_model))

# Gradient Descent - Backpropagation 기법으로 최적화
optimizer = tf.train.GradientDescentOptimizer(0.01).minimize(cost) # learning_rate = 0.01



#---------------------------------------------------------------------------------------------------- 4. 훈련을 위한 세션 시작
sess = tf.Session()


sess.run(tf.global_variables_initializer()) # 변수 초기화


for epoch in range(25): # 훈련을 25번 반복
    avg_cost = 0.

    # 1번 훈련시 전체 훈련 데이터를 사용하려면 100개씩 몇번 가져와야 하는지 계산하여 반복
    total_batch = int(mnist.train.num_examples / 100)
    for i in range(total_batch):
        # 전체 훈련 데이터(mnist.train)에서 100개씩 데이터를 가져옵니다.
        # (100, 784) (100, 10)
        batch_xs, batch_ys = mnist.train.next_batch(100)

        # optimizer와 cost 오퍼레이션을 실행합니다.
        _, c = sess.run([optimizer, cost], feed_dict={x: batch_xs, y: batch_ys})

        # 현재까지 평균 손실(loss)를 누적합니다.
        avg_cost += c / total_batch

    # 훈련 1번 끝날때 마다 중간 결과를 출력
    print("Epoch:", '%04d' % (epoch+1), "cost=", "{:.9f}".format(avg_cost))


print("최적화 완료")



#---------------------------------------------------------------------------------------------------- 5. 정확도 측정
# 라벨값 y와 모델로 계산된 값 y_model이 똑같이 같은 인덱스가 제일 크다고 하는지 검사
# ( tf.argmax 함수가 배열에서 가장 큰 값을 가리키는 인덱스를 리턴합니다.. )
# 결과적으로 correct_prediction는 True 또는 False 값의 리스트를 가지게 됨
#
# tf.argmax에 대한 자세한 내용은 다음 포스팅 참고
# Tensorflow 예제 - tf.argmax 함수 사용법 ( http://webnautes.tistory.com/1234 )
correct_prediction = tf.equal(tf.argmax(y_model, 1), tf.argmax(y, 1))


# tf.cast 함수를 사용하여 True 또는 False를 실수 1 또는 0으로 변환
# 전체 데이터가 일치한다면 모든 값이 1이며 평균인 accuracy는 1이 되어야 합니다.
#
# tf.reduce_mean에 대한 자세한 내용은 다음 포스팅 참고
# Tensorflow 예제 - tf.reduce_mean 함수 사용법 ( http://webnautes.tistory.com/1235 )
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

# 정확도 측정을 위해서 훈련 데이터(mnist.train) 대신에 별도의 테스트 데이터(mnist.test)를 사용해야 합니다.
print("Accuracy:", sess.run(accuracy, feed_dict={x: mnist.test.images, y: mnist.test.labels}))

sess.close()
