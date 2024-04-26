#define ll long long
class Solution {
    ll help(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<ll>>&dp){
        if(i<0 || i>=m || j<0 || j>=n) return INT_MAX;
        if(i==m-1 && j<=n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        ll op1 = INT_MAX;
        
        for(int k = 0;k<n;k++){
            if(k!=j){

        op1 = min(op1,grid[i][j]+help(grid,m,n,i+1,k,dp));
            }
        }
       
        return dp[i][j]=op1;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,-1));
        ll mini = INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            dp[0][j] = help(grid,m,n,0,j,dp);
            mini = min(mini,dp[0][j]);
        }
        return mini;
    }
};