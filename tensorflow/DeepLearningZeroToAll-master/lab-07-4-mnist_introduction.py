# Lab 7 Learning rate and Evaluation
import tensorflow as tf
import random
import matplotlib.pyplot as plt
tf.set_random_seed(777)  # for reproducibility

from tensorflow.examples.tutorials.mnist import input_data #숫자읽는거 텐서에서 라이브러리로 만들어저잇음.
# Check out https://www.tensorflow.org/get_started/mnist/beginners for
# more information about the mnist dataset
mnist = input_data.read_data_sets("MNIST_data/", one_hot=True) # one_hot=True 로하면 불러올때 알아서 원핫으로 만들어준다.

nb_classes = 10

# MNIST data image of shape 28 * 28 = 784
X = tf.placeholder(tf.float32, [None, 784])
# 0 - 9 digits recognition = 10 classes
Y = tf.placeholder(tf.float32, [None, nb_classes])

W = tf.Variable(tf.random_normal([784, nb_classes])) # 28pixel * 28 pixel classific한 데이터이므로 행* 렬
b = tf.Variable(tf.random_normal([nb_classes])) # 1~ 10이니 10개의 출력

# Hypothesis (using softmax)
hypothesis = tf.nn.softmax(tf.matmul(X, W) + b) #확률적으로 나오게 해준다~

cost = tf.reduce_mean(-tf.reduce_sum(Y * tf.log(hypothesis), axis=1)) #cost는 크로스 엔트로피 사용~
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1).minimize(cost)

# Test model
is_correct = tf.equal(tf.arg_max(hypothesis, 1), tf.arg_max(Y, 1)) #arg_max하면 [0,0,1,0,0] 값을 2로출력해주는듯.
# Calculate accuracy
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))

# parameters
training_epochs = 15 #전체 데이터 set을 한번 다학습시키는것~ 전체데이터를 15번 학습하겠다. 많을수록 좋다..
batch_size = 100 #한번에 모든 데이터를 올리면 메모리가 못버티니 100개씩 메모리에 옮기겟다.

with tf.Session() as sess:
    # Initialize TensorFlow variables
    sess.run(tf.global_variables_initializer())
    # Training cycle
    for epoch in range(training_epochs):
        avg_cost = 0
        total_batch = int(mnist.train.num_examples / batch_size) #배치사이즈에따라 몇번 펌프할것인가?

        for i in range(total_batch): #토탈배치만큼 100개씩학습
            batch_xs, batch_ys = mnist.train.next_batch(batch_size) # 100개읽어오겟다 1~100 101~200 201~300 이렇게 읽어온다.
            c, _ = sess.run([cost, optimizer], feed_dict={
                            X: batch_xs, Y: batch_ys})
            avg_cost += c / total_batch

        print('Epoch:', '%04d' % (epoch + 1), #하나의 에폭이 끝날때마다 출력~
              'cost =', '{:.9f}'.format(avg_cost))

    print("Learning finished")

    # Test the model using test sets
    print("Accuracy: ", accuracy.eval(session=sess, feed_dict={#정확도 평가 sess에 안넣고 하는 accuracy.eval 이라는 방법
          X: mnist.test.images, Y: mnist.test.labels}))

    # Get one and predict 한번 테스트 해보는 단계
    r = random.randint(0, mnist.test.num_examples - 1)
    print("Label: ", sess.run(tf.argmax(mnist.test.labels[r:r + 1], 1)))
    print("Prediction: ", sess.run(
        tf.argmax(hypothesis, 1), feed_dict={X: mnist.test.images[r:r + 1]}))

    plt.imshow(
        mnist.test.images[r:r + 1].reshape(28, 28),
        cmap='Greys',
        interpolation='nearest')
    plt.show()


'''
Epoch: 0001 cost = 2.868104637
Epoch: 0002 cost = 1.134684615
Epoch: 0003 cost = 0.908220728
Epoch: 0004 cost = 0.794199896
Epoch: 0005 cost = 0.721815854
Epoch: 0006 cost = 0.670184430
Epoch: 0007 cost = 0.630576546
Epoch: 0008 cost = 0.598888191
Epoch: 0009 cost = 0.573027079
Epoch: 0010 cost = 0.550497213
Epoch: 0011 cost = 0.532001859
Epoch: 0012 cost = 0.515517795
Epoch: 0013 cost = 0.501175288
Epoch: 0014 cost = 0.488425370
Epoch: 0015 cost = 0.476968593
Learning finished
Accuracy:  0.888
'''
