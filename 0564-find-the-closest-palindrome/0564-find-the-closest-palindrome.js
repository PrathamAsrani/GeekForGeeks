/**
 * @param {string} num
 * @return {string}
 */
var nearestPalindromic = function(num) {
    let n = num.length;
    let x = BigInt(num);
    
    if (n === 1) return (x - BigInt(1)).toString();

    let candidates = [
        BigInt(Math.pow(10, n - 1)) - BigInt(1), 
        BigInt(Math.pow(10, n)) + BigInt(1)
    ];

    let half = num.substring(0, Math.floor((n + 1) / 2));
    let prefix = BigInt(half);
    let prefixes = [prefix - BigInt(1), prefix, prefix + BigInt(1)];

    for (let p of prefixes) {
        let left = p.toString();
        let right = left.split('').reverse().join('');
        if (n % 2 !== 0) right = right.substring(1);
        candidates.push(BigInt(left + right));
    }

    let closest = null;
    let minDiff = BigInt(Number.MAX_SAFE_INTEGER);
    
    for (let cand of candidates) {
        if (cand === x) continue;
        
        let diff = cand > x ? cand - x : x - cand;
        
        if (diff < minDiff || (diff === minDiff && cand < closest)) {
            closest = cand;
            minDiff = diff;
        }
    }

    return closest.toString();
};
