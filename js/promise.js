new Promise((resolve, reject) => {
    console.log('Initial')

    resolve()
})
.then(() => {
   // throw new Error("Failed")
    console.log("first then")
})
.then(() => {
    console.log('Another Then')
})
.catch(() =>  {
    console.log('First catch')
})
.then(() => {
    console.log("Last then")
})
