# Reference: https://www.rabbitmq.com/tutorials/tutorial-one-python.html

import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')

def callback(ch, method, properties, body):
	print(" [x] Received %r" % body)

channel.basic_consume(callback, queue='hello', no_ack=True)

print(' [x] Waiting for messages. CTRL+C to exit')
channel.start_consuming()
