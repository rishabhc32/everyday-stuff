var express = require('express'),
    https = require('https'),
    bodyParser = require('body-parser'),
    request = require('request'),
    fs = require('fs'),
    path = require('path');

const options = {
    key: fs.readFileSync(path.resolve('/home/spooderman/Documents/everyday-stuff/js/node-proxy/ssl-certificate/server.key')),
    cert: fs.readFileSync(path.resolve('/home/spooderman/Documents/everyday-stuff/js/node-proxy/ssl-certificate/server.crt'))
};

const app = express();

app.get('/myQuote', (req, res) => {
    console.log('Piping response');
    request.get('http://quotes.stormconsultancy.co.uk/quotes/1.json').pipe(res);
});

app.get('/hello' ,(req, res) => {
    res.send('Hello');
});

https.createServer(options, app).listen(8080);
