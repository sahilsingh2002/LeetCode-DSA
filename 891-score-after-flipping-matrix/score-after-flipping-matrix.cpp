class Solution {
    void flipr(vector<vector<int>>&grid,int i){
        for(int j=0;j<grid[0].size();j++){
            grid[i][j]=!grid[i][j];
        }
    }
    void flipc(vector<vector<int>>&grid,int j){
        for(int i=0;i<grid.size();i++){
            grid[i][j]=(grid[i][j]==0?1:0);
        }
    }

public:

    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                flipr(grid,i);
            }
        }
        for(int j=1;j<n;j++){
            int zeroes = 0;
            int ones = 0;
            for(int i=0;i<m;i++){
                zeroes+=(grid[i][j]==0?1:0);
                ones+=grid[i][j];
            }
            if(zeroes>ones){
            // cout<<zeroes<<" "<<ones<<endl;
                
                flipc(grid,j);
            }
        }
        int p=0;
        for(int i=0;i<m;i++){
            int num = 0;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j]==1){

                num+=pow(2,n-1-j);
                }
            

            }
            // cout<<num<<endl;
            p+=num;
        }
        
        return p;

    }
};