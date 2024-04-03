class Solution {
    bool dfs(vector<vector<char>>& board, int i, int j, string& word,vector<vector<int>>&vis){
        if(!word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[0] || vis[i][j]) return false;
        
        vis[i][j]=1;
        string s = word.substr(1);
        bool res = dfs(board,i-1,j,s,vis) || dfs(board,i,j-1,s,vis) || dfs(board,i,j+1,s,vis) || dfs(board,i+1,j,s,vis);
       vis[i][j]=0;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(dfs(board,i,j,word,vis)) return true;
            }

        }
        return false;
       
        
        
    }
};