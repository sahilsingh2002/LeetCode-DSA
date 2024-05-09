typedef long long ll;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       sort(happiness.begin(),happiness.end());
       int idx = happiness.size()-1;
       ll curr = 0;
       ll ans = 0;
       while(k>0){
        ll x = happiness[idx]-curr;
        if(x<0) x=0;
        ans+=x;
        idx--;
        curr++;
        k--;
       }
       return ans;
    }
};