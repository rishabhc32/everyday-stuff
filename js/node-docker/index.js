const express = require('express')

const HOST = '0.0.0.0'
const PORT = '8080'

const app = express();

app.get('/', (req, res) => {
    res.send("Hello, World!")
})

app.listen(PORT, HOST);
console.log(`Started Server on ${HOST}:${PORT}`)
