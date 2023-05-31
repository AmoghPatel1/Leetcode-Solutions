/**
 * @param {number} millis
 */
async function sleep(millis) {
    await new Promise(response => setTimeout(response, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */