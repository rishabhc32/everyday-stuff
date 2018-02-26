const amqp = require('amqplib/callback_api')

amqp.connect('amqp://localhost', (err, conn) => {
	conn.createChannel( (err, ch) => {
		var q = 'hello'

		ch.assertQueue(q, {durable: false})

		console.log(' [x] Waiting for message in %s. CTRL+C to exit', q)
		ch.consume(q, (msg) => {
			console.log(' [x] Received %s', msg.content.toString())
		}, {noAck: true})
	})
})
