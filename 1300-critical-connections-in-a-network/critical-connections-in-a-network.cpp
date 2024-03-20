class Solution {
public:
int time = 1;
    void dfs(vector<int>&vis,vector<int>&ti,vector<int>&lti,unordered_map<int,
    vector<int>>&adj,int node,int par,vector<vector<int>>&bridge){
        vis[node]=1;
        ti[node]=time;
        lti[node] = time;
        time++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
            dfs(vis,ti,lti,adj,it,node,bridge);
            lti[node] = min(lti[node],lti[it]);
            if(lti[it]>ti[node]) bridge.push_back({it,node});
            }
            else{
                lti[node] = min(lti[it],lti[node]);
            }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0);
        unordered_map<int,vector<int>>adj;
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>ti(n,0);
        vector<int>lti(n,INT_MAX);
        vector<vector<int>>bridge;
        dfs(vis,ti,lti,adj,0,-1,bridge);
       
        
        
        return bridge;

    }
};