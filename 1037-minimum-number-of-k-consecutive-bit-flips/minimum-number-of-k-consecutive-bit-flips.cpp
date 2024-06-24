class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>flipped(n,0);
       int ans = 0,t = 0;
       for(int i=0;i<n;i++){
        if(i>=k){
            t-=flipped[i-k];
        }
        if(nums[i]==1 && (t&1) || nums[i]==0 && !(t&1)){
            if(i+k>n) return -1;
            ans++;
            t++;
            flipped[i]=1;
        }
       }
       return ans;
    }
};