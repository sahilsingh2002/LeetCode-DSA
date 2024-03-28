class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int l = 0;
        int r = 0;
        int maxl = INT_MIN;
        while(r<nums.size()){
            freq[nums[r]]++;
            
            while(freq[nums[r]]>k && l<r){
                freq[nums[l++]]--;
                
            }
            maxl = max(maxl,(r-l)+1);
            r++;
            
        }
        return maxl;
    }
};