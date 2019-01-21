const httpProxy = require('http-proxy');
const http = require('http');
const express = require('express');

const app = express();

const proxy = httpProxy.createProxyServer({});

app.get('/', (req, res) => {res.send('Hello') });

let server = http.createServer((req, res) => {
    let p = proxy.web(req, res, {
        target: 'http://localhost:5000'
    });
});

proxy.listen(4000);

app.listen(5000);
