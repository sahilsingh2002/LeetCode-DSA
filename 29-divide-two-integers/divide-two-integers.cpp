typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(divisor==1 || divisor==-1) return dividend*divisor;
        int sign = ((dividend<0 && divisor<0) || (dividend>0 && divisor>0))?1:-1;
        cout<<sign<<endl;
        ll a = abs(dividend);
        ll b= abs(divisor);
        ll ans = 0;
        while(a>=b){
            a-=b;
            ans++;

        }
        cout<<ans<<endl;
        return ans*sign;
    }
};