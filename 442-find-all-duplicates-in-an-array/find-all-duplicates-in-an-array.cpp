class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num-1]<0){
                ans.push_back(abs(nums[i]));
            }
            nums[num-1]=nums[num-1]*-1;
        }
        return ans;
    }
};