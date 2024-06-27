class Solution {
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[m-1][n-1]==1) return dp[m-1][n-1]= 0;
        if(i==m-1 && j==n-1) return dp[i][j]=1;
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a = solve(grid,i+1,j,dp);
        int b =solve(grid,i,j+1,dp);
        return dp[i][j]=a+b;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid,0,0,dp);
    }
};