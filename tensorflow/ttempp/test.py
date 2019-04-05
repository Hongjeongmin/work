import numpy as np
import matplotlib.pyplot as plt

# Import MNIST data
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("/tmp/data/", one_hot=True)


print("훈련 이미지 :",  mnist.train.images.shape)
print("훈련 라벨:",  mnist.train.labels.shape)
print("테스트 이미지 : ", mnist.test.images.shape)
print("테스트 라벨 : ", mnist.test.labels.shape)
print("검증 이미지 : ", mnist.validation.images.shape)
print("검증 라벨 : ", mnist.validation.labels.shape)
print('\n')


mnist_idx = 100


print('[label]')
print('one-hot vector label = ', mnist.train.labels[mnist_idx])
print('number label = ', np.argmax(mnist.train.labels[mnist_idx]))
print('\n')

print('[image]')

for index, pixel in enumerate(mnist.train.images[mnist_idx]):
    if index % 28 == 0:
        print('\n')
    else:
        print("%10f" % pixel, end="")
print('\n')


plt.figure(figsize=(5, 5))
image = np.reshape(mnist.train.images[mnist_idx], [28, 28])
plt.imshow(image, cmap='Greys')
plt.show()
