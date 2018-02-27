// Reference: https://www.rabbitmq.com/tutorials/tutorial-one-javascript.html

const amqp = require('amqplib/callback_api')

amqp.connect('amqp://localhost', (err, conn) => {
	conn.createChannel( (err, ch) => {
		var q = 'hello'

		ch.assertQueue(q, {durable: false})
		msg = 'I am disco dancer!!'
		ch.sendToQueue(q, new Buffer(msg))
		console.log(' [x] sent %s ', msg)
	})
	setTimeout( () => {
		conn.close()
		process.exit(0)
	}, 500)
})

