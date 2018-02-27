# RabbitMQ
This repo is aimed to learn __RabbitMQ__ or any __MQ__ for general.

### What is MQ after all?

 > A message queue provides an asynchronous communication protocol, a system that puts a message onto a message queue and does not require an immediate response to continuing processing. This way of handling messages decouple the producer from the consumer. The producer and the consumer of the message do not need to interact with the message queue at the same time. 

In simple words a producer places a message in queue, and continues its work. A consumer takes the message from queue processes it and returns the result. Thus decoupling two compnents.
* __Producing__ means nothing more than sending. A program that sends messages is a producer
* A __queue__ is essentially a large message buffer. Many producers can send messages that go to one queue, and many consumers can try to receive data from one queue. 
* __Consuming__ has a similar meaning to receiving. A consumer is a program that mostly waits to receive messages: 
![Visualization](https://www.cloudamqp.com/img/blog/message-queue-example.png)

__Example__
> Imagine that your web service has to be highly available and ready to receive new request instead of being blocked by the processing of previous requests. In this case it is ideal to put a queue between the web service and the processing service. The web service can put a "start processing" message on a queue and the other process can handle messages in order. 

### RabbitMQ
RabbitMQ is a message broker: it accepts and forwards messages.

In the diagram below, __P__ is our producer and __C__ is our consumer. The box in the middle is a queue - a message buffer that RabbitMQ keeps on behalf of the consumer.

![rabbitmq visualization](https://www.rabbitmq.com/img/tutorials/python-one.png)

##### NodeJS
* _module_: `npm install amqplib`
* _send.js_: Send message to queue
* _receive.js_: Receive message form queue
##### Python
* _module_: `pip install pika`
* _receive.py_: Receive message from queue
##### Steps
* Install `RabbitMQ`
* Start MQ server: `sudo rabbitmq-server`
* Send Message: `node send.js`
* Receive Message: `node receive.js` _or_ `python receive.py`
##### Output
* __Starting RabbitMQ server__
![Starting Server](https://i.imgur.com/jsGRIlb.png)

* __Sending and receiving message__
![Sending and receiving message](https://i.imgur.com/Fz2MpRo.png)
### Rerference
* [RabbitMQ 'hello-world' tutorial](https://www.rabbitmq.com/tutorials/tutorial-one-javascript.html)
* [Understanding MQ](https://www.cloudamqp.com/blog/2014-12-03-what-is-message-queuing.html)