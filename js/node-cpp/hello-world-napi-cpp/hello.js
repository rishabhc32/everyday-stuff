const addon = require('bindings')('hello')

const ans = addon.callMyFunction();
console.log(ans);