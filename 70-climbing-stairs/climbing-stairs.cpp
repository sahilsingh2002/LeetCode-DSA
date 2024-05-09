class Solution {
    // int help(int n,vector<int>&dp){
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]=help(n-1,dp)+help(n-2,dp);

    // }
public:
    int climbStairs(int n) {
        int a=1,b=2;
        if(n==1) return a;
        if(n==2) return b;
        vector<int>dp(n+1,0);
        // return help(n,dp);
        for(int i=3;i<=n;i++){
           int curr = a+b;
           a=b;
           b = curr;

        }
        return b;
    }
};