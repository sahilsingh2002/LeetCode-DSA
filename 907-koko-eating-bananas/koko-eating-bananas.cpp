typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int maxm = 0;
       for(int i:piles){
        maxm = max(maxm,i);
       } 
       ll l = 1,r=maxm;
       while(l<=r){
        ll hours = 0;
        ll mid = l+(r-l)/2;
        for(int i:piles){
           hours+=(i/mid+(i%mid>0?1:0));
        }
        
        if(hours<=h){
            maxm = mid;
            r=mid-1;
        }
        else{
            l = mid+1;
        }
       }
       return maxm;
    }
};