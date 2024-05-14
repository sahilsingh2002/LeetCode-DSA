class Solution {
    int help(vector<vector<int>>&grid,int m,int n, int i,int j){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(grid[i][j]==0) return 0;
        int p = grid[i][j];
        grid[i][j]=0;
        int op1 = p+help(grid,m,n,i+1,j);
        int op2 = p+help(grid,m,n,i-1,j);
        int op3 = p+help(grid,m,n,i,j+1);
        int op4 = p+help(grid,m,n,i,j-1);
        grid[i][j]=p;
        return max(op1,max(op2,max(op3,op4)));

    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxm = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){

                maxm =max(maxm,help(grid,m,n,i,j));
                }
            }
        }
        return maxm==INT_MIN?0:maxm;
    }
};