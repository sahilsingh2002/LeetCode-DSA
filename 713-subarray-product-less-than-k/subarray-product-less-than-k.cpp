class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int sum = 1;
        int cnt = 0;
        int l=0,r=0;
        
        if(k<=1) return 0;
        while(r<nums.size()){
           sum*=nums[r];
           while(sum>=k) sum/=nums[l++];
           cnt +=1+(r-l);
           r++;
            
        }
        
        return cnt;
    }
};