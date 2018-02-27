# RabbitMQ
This repo is aimed to learn __RabbitMQ__ or any __MQ__ for general.

### Inspiration
I was reading an article on _NodeJS_ describing where it shines and what are its downfalls ([Article link](https://medium.com/the-node-js-collection/why-the-hell-would-you-use-node-js-4b053b94ab8e)). NodeJS operates on **_event-based calbacks_** in a **single thread** _event-loop_. Therefore, NodeJS really shines in building fast, scalable application capable of handling a huge number of **_simultaneous/concurrent connections_**. 
> The main idea of Node.js: use non-blocking, event-driven I/O to remain lightweight and efficient in the face of data-intensive real-time applications that run across distributed devices.

But where it falls is **_heavy server-side computation/processing_**. In general, any CPU intensive operation will nullify benefits of Node because incoming requests will be blocked while the thread is occupied with the number-crunching.
> No, you definitely don’t want to build a Fibonacci computation server in Node.js. 

One of the solution he suggests is to,
> offload all heavy computation to background processes written in a more appropriate environment, and have them communicate via a **message queue server** like RabbitMQ.

From there I started reading and learning about _RabbitMQ_ and _MQ(message queue)_ in general.
### What is MQ after all?

 > A _**M**essage **Q**ueue_ provides an asynchronous communication protocol, a system that puts a message onto a message queue and does not require an immediate response to continuing processing. This way of handling messages decouple the producer from the consumer. The producer and the consumer of the message do not need to interact with the message queue at the same time. 

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
* Install _RabbitMQ_
* Start MQ server: `sudo rabbitmq-server`
* Send Message: `node send.js`
* Receive Message: `node receive.js` _or_ `python receive.py`
#### Output
* __Starting RabbitMQ server__
![Starting Server](https://i.imgur.com/jsGRIlb.png)

* __Sending and receiving message__
![Sending and receiving message](https://i.imgur.com/Fz2MpRo.png)
### Rerference
* [RabbitMQ 'hello-world' tutorial](https://www.rabbitmq.com/tutorials/tutorial-one-javascript.html)
* [Understanding MQ](https://www.cloudamqp.com/blog/2014-12-03-what-is-message-queuing.html)
