class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minday = INT_MAX;
        int n = bloomDay.size();
        if(n<(long long)m*k) return -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int r= *max_element(bloomDay.begin(),bloomDay.end());
        while(l<=r){
            int mid = l+(r-l)/2;
            int bouq = 0;
            int cnt = 0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid) cnt++;
                else {
                    bouq+=(cnt/k);
                    cnt = 0;
                }
            }
            bouq+=cnt/k;
            cnt = 0;
            if(bouq>=m){
                minday = min(minday,mid);
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return minday;
        
    }
};