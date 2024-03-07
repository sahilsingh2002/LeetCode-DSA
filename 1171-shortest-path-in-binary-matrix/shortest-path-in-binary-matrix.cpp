class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0 || grid[grid.size()-1][grid[0].size()-1]!=0) return -1;
       int m = grid.size();
       int n = grid[0].size();
       queue<vector<int>>st;
       vector<vector<int>>dist(m,vector<int>(n,1e9));
       st.push({1,0,0});
       vector<int>drow = {0,0,1,-1,1,-1,1,-1};
       vector<int>dcol = {1,-1,0,0,1,-1,-1,1};
       dist[0][0]=1;

       while(!st.empty()){
           auto vec1 = st.front();
           int wt=vec1[0];
           int x = vec1[1];
           int y = vec1[2];
           st.pop();
           for(int i=0;i<8;i++){
               int row = x+drow[i];
               int col = y+dcol[i];
               if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==0){
                   
                   if(wt+1<dist[row][col]){
                       cout<<row<<" "<<col<<" ";
                       
                       dist[row][col]=wt+1;
                       cout<<dist[row][col]<<endl;
                       st.push({dist[row][col],row,col});
                   }
               }
           }

       }
       return dist[m-1][n-1]!=1e9?dist[m-1][n-1]:-1;
        
    }
};