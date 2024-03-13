class Solution {
    void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int i){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        if(len<n-1) return -1;
        unordered_map<int,vector<int>>adj;
        vector<int>vis(n,0);
        int ans=0;
        for(auto it : connections){
           adj[ it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }
        return ans-1;

    }
};