/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    let l=0,r=Math.round(Math.sqrt(c),0);
    while(l<=r){
        let sum = (l*l)+(r*r);
        if(sum==c) return true;
        else if(sum<c) l++;
        else r--;
    }
    return false;
};