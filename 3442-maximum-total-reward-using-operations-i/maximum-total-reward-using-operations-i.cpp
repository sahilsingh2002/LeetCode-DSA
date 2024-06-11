class Solution {
    int help(vector<int>&p,int i,int currRew,vector<vector<int>>&dp){
        if(currRew>p.back()) return currRew;
        if(i==p.size()) return currRew;
        if(dp[i][currRew]!=-1) return dp[i][currRew];
        int a = (currRew<p[i])?help(p,i+1,currRew+p[i],dp):currRew;
       
       int b = help(p,i+1,currRew,dp);
        return dp[i][currRew]=max(a,b);
    }
public:
    
    int maxTotalReward(vector<int>& p) {
        
        sort(p.begin(),p.end());
        vector<vector<int>>dp(p.size()+1,vector<int>(p.back()+1,-1));
        return help(p,0,0,dp);
    }
};