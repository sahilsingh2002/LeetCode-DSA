typedef long long ll;
class Solution {
   

public:
    bool judgeSquareSum(int c) {

    ll l = 0,r=sqrt(c);
    while(l<=r){
        ll one = l*l;
        ll two = r*r;
        ll sum = one+two;
        if(sum==c) return true;
        else if(sum<c) l++;
        else r--;
    }
    return false;
    }
    
};