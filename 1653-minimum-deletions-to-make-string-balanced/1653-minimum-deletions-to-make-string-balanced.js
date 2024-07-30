/**
 * @param {string} s
 * @return {number}
 */
var minimumDeletions = function(s) {
    let ans = 0, cnt  = 0;
    for(let c of s){
        if(c === 'b') cnt++
        else if(cnt > 0) ans++, cnt--
    }
    return ans
};