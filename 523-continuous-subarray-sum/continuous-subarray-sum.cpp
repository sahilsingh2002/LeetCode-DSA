class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>freq;
       freq[0]=-1;
       int sum = 0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(freq.find(sum%k)!=freq.end()){
            if(i-freq[sum%k]>=2) return true;
        }
        else{
            freq[sum%k]=i;
        }
       }
       return false;
    }
};