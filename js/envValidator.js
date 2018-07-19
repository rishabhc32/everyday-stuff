function validateEnv(requiredEnv) {
    if(requiredEnv instanceof Array && requiredEnv.length > 0) {
        let unsetEnv = requiredEnv.filter((env) => !(typeof env !== 'undefined'))

        if (unsetEnv.length > 0) {
            throw new Error("Required ENV variables are not set: [" + unsetEnv.join(', ') + "]");
        }

        return true;
    }  

    return false;
}

validateEnv(['NODE_ENV'])
