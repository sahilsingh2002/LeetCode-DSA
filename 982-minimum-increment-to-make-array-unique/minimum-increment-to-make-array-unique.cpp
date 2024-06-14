class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>freq(1e6+1,0);
        int maxm = 0;
        for(int i:nums){
            freq[i]++;
            maxm = max(maxm,i);
        }
        int cnt = 0;

        int l=0,r=1;
        while(l<=maxm && r<freq.size()){
            while(freq[l]>1){

                if(r<l) r = l+1;
                if(freq[r]==0){
                    
                    freq[r]++;
                    cnt+=r-l;
                    freq[l]--;
                    
                }
                r++;
               
            }
            l++;
        }
        
        return cnt;
    }
};