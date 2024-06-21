class Solution {
    int cando(vector<int>&weights,int mid,int days){
        int cnt = 0;
        int p = 0;
        for(int i=0;i<weights.size();i++){
           p+=weights[i];
           if(weights[i]>mid) return false;
            if(mid<p){
                cnt++;
                p=weights[i];
            }
        }
        if(p>0) cnt++;
        return cnt<=days;
        }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int total = accumulate(weights.begin(),weights.end(),0LL);
        if(days==1) return total;
        int l = 1;
        int r = (total);
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(cando(weights,mid,days)){
                ans = mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};