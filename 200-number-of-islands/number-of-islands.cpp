class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        queue<pair<int,int>>touch;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;

                    vis[i][j]=1;
                    touch.push({i,j});
                    while(!touch.empty()){
                        auto [x,y]=touch.front();
                        touch.pop();
                        if(x-1>=0 && grid[x-1][y]=='1' && !vis[x-1][y]){
                            vis[x-1][y]=1;
                            touch.push({x-1,y});
                        }
                        if(x+1<m && grid[x+1][y]=='1' && !vis[x+1][y]){
                            vis[x+1][y]=1;
                            touch.push({x+1,y});
                        }
                        if(y-1>=0 && grid[x][y-1]=='1' && !vis[x][y-1]){
                            vis[x][y-1]=1;
                            touch.push({x,y-1});
                        }
                        if(y+1<n && grid[x][y+1]=='1' && !vis[x][y+1]){
                            vis[x][y+1]=1;
                            touch.push({x,y+1});
                        }
                    }
                }
            }
        }
        return count;
    }
};