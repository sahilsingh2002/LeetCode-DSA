class Solution {
    int solve(vector<int>&nums,int i,int firstRob,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][firstRob]!=-1) return  dp[i][firstRob];
        int a = 0;
        if(i==0){
            a = nums[i]+solve(nums,i+2,1,dp);
        }
        else if(i==nums.size()-1){
            a = firstRob?solve(nums,i+2,1,dp) : nums[i]+solve(nums,i+2,0,dp);
        }
        else a = nums[i]+solve(nums,i+2,firstRob,dp);
        int b = solve(nums,i+1,firstRob,dp);
        return dp[i][firstRob]=max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return solve(nums,0,0,dp);
    }
};