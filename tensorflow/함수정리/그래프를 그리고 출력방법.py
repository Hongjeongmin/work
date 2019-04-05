node1 = tf.constant(3.0, tf.float32)
#constant 는 노드를 만들겠다
node2 = tf.constant(4.0)
#파라미터 없으면 자동적으로 float32 로 설정
node3 = tf.add(node1,node2)
#두개의 노드를 더하라는 뜻
sess - tf.session()
print(sess,run([node1,node2]))
print(sess.run(node3))
#실행결과는 [3.0, 4.0]
#              7.0


####################실행시키는 단계에서 값을 던져주고싶다
a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
#비어 있는 node 생성
adder_node = a + b
#노드두개를 더하는 adder_node생성
sess.run(adder_node, feed dict={a: 3, b: 4.5})
#섹션으로 adder_node를 실행시키는데 adder_node는 a와 b가 들어가지만
#빈공간이므로 feed dict={a: 3, b: 4.5} 딕셔너리 형태로 넘겨주는거 같다~
sess.run(adder_node, feed_dict={a: [1,3], b: [2,4]})
#실행결과  [3.    7.] 리스트 형태로 주면 리스트형태의 결과를 출력
