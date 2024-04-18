class Solution {
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        // queue<pair<int,int>>q;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
                
        //         if(grid[i][j]==1){
        //            q.push({i,j});
                  
        //            break;
        //         }
        //     }
        //     if(!q.empty()) break;
        // }
        // vector<int>drow = {0,0,-1,1};
        // vector<int>dcol = {-1,1,0,0};
        // int ans = 0;
        // while(!q.empty()){
        //     auto x = q.front();
        //     int i=x.first;
        //     int j = x.second;
        //     q.pop();
        //     vis[i][j]=1;

        //     for(int k=0;k<4;k++){
        //         int row = i+drow[k];
        //         int col = j+dcol[k];
        //         if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]==0){
                
        //             ans++;
        //         }
        //         else if(!vis[row][col]){
        //             q.push({row,col});
        //             vis[row][col]=1;
                   
        //         }
        //     }
            
        // }
        // return ans;

        // second approach 
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0 && grid[i-1][j]) ans-=2;
                    if(j>0 && grid[i][j-1]) ans-=2;
                }
            }
        }
        return ans;
    }
};