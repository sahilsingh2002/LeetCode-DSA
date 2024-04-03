class Solution {
    bool dfs(vector<vector<char>>& board, int i, int j, string& word){
        if(!word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[0]) return false;
        char m = board[i][j];
        board[i][j]='*';
        string s = word.substr(1);
        bool res = dfs(board,i-1,j,s) || dfs(board,i,j-1,s) || dfs(board,i,j+1,s) || dfs(board,i+1,j,s);
        board[i][j]=m;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(dfs(board,i,j,word)) return true;
            }

        }
        return false;
       
        
        
    }
};