/*
    https://javascript.info/async
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await
*/

const request = require('request')
const fetch = require('node-fetch')

var options = {
    url: 'https://api.github.com/users/rishabhc32',
    headers: {
        'User-Agent': 'request'
    }
}

// function returning promise
function get_response() {
    return new Promise((resolve, reject) => {
        request.get(options, (err, res, body) => {
            if(err) 
                reject(err)
            else
                resolve(JSON.parse(body))
        })
    })
}

//resolving promise
get_response()
.then((result) => {
    console.log(result)
})
.catch((err) => {
    console.log('Error occured')
})
 
options.url = 'hello'

//handling rejected promise
get_response() 
.then((result) =>  {
    console.log(result)
})
.catch((err) => {
    console.log(`Error: ${err.message}`)
})

//async await
let another_response = async function() {
    options.url = 'https://api.github.com/users/mittalprince'

    //await get_response().then((result) => console.log(result))
    let result = await get_response()
    console.log(`login id: ${result.login} \nid: ${result.id}`)

    options.url = 'yoyo'
    get_response().then(null, (err) => console.log(`Error: ${err.message}`))

    //error handling with await
    try {
        let result = await get_response()
    } catch(err) {
        console.log(`Again Error: ${err.message}`)
    }
 }()  

 //using Promise.all
let UserNames = ['rishabhc32', 'mittalprince', 'geekychaser']
let req = UserNames.map(name => fetch(`https://api.github.com/users/${name}`))

Promise.all(req)
.then((result) => {
    result.forEach( (element) => {
        console.log(`${element.url}: ${element.status}`)
    })
})

//fail safe Promise.all(error handling in Promise.all)
let url = 'https://api.github.com/users/iliakan'

//Promise.all([fetch(url), fetch('shit')])
Promise.all([fetch(url), fetch('shit').catch(error => {return error})])
.then(response => { 
  console.log(`${url}: ${response[0].status}`)
  console.log(`Error: ${response[1].message}`)
})
