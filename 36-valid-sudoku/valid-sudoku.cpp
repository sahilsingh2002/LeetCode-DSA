class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int curr = board[i][j];
                for(int k=0;k<9;k++){
                    if((board[k][j]==curr && k!=i) || (board[i][k]==curr && k!=j)) {
                       
                        return false;
                        }
                }
                for(int k=0;k<3;k++){
                    for(int m=0;m<3;m++){
                        int row = (i/3)*3+k;
                        int col= (j/3)*3+m;
                        if(board[row][col]==curr && (row!=i || col!=j)) return false; 
                    }
                }
            }
        }
         return true;
    }
};