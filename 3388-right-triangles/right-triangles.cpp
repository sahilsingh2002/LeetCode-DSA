#define ll long long
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<ll>rowc(m,0);
        vector<ll>colc(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    rowc[i]++;
                    colc[j]++;
                }
            }
        }
        ll cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   cnt+=(rowc[i]-1)*(colc[j]-1);
                }
            }
        }
        return cnt;
        
    }
};