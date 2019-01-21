var redis = require("redis"),
    client = redis.createClient();
client.quit();

// if you'd like to select database 3, instead of 0 (default), call
// client.select(3, function() { /* ... */ });

client.on("error", function (err) {
    console.log("Error " + err);
});

client.hmset("yo", {
    "0123456789": "abcdefghij", // NOTE: key and value will be coerced to strings
    "some manner of key": "a type of value"
});
client.hgetall("hello", function (err, replies) {
    //console.log(replies["0123456789"]);
    client.quit();
});
