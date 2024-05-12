class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>>ans(m-2,vector<int>(m-2,0));
        for(int i=1;i<m-1;i++){
            for(int j=1;j<m-1;j++){
                int p = INT_MIN;
                for(int k = i-1;k<=i+1;k++){
                    for(int m = j-1;m<=j+1;m++){
                        p = max(p,grid[k][m]);
                    }
                }
                ans[i-1][j-1]=p;
            }
        }
        return ans;
    }
};