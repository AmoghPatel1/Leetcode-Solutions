/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memory = {};
    return function(...args) {
        const key = JSON.stringify(args);
        if(key in memory) return memory[key];
        const output = fn(...args);
        memory[key] = output;
        return output;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */