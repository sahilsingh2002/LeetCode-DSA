class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int>prev(n+1,0);
       prev[0]=1;
       int odd = 0;
       int ans = 0;
       for(int i:nums){
        odd+=i&1;
        if(odd-k>=0){
            ans+=prev[odd-k];
        }
        prev[odd]++;
       }
       return ans;
    }
};