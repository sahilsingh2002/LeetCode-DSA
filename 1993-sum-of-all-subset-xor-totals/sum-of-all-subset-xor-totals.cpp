class Solution {
public:
int help(vector<int>&nums,int idx,int sum){
    if(idx>=nums.size()) return sum;
    int a = help(nums,idx+1,sum^nums[idx]);
    int b = help(nums,idx+1,sum);
    return a+b;

}

    int subsetXORSum(vector<int>& nums) {
        return help(nums,0,0);
    }
};