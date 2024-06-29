class Solution {
    void dfs(int curr,int par,vector<vector<int>>&ans,vector<int>adj[]){
       for(int it:adj[curr]){
        if(ans[it].empty() || ans[it].back()!=par){
            ans[it].push_back(par);
            dfs(it,par,ans,adj);
        }
       }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
       
            for(int i=0;i<n;i++){
                dfs(i,i,ans,adj);
            }
        
        return ans;
    }
};