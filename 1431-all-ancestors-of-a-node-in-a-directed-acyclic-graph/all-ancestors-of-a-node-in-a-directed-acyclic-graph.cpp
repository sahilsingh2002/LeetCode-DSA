class Solution {
    void filldata(set<int>&par,vector<int>&vis,vector<int>adj[],int i){
        if(vis[i] || adj[i].size()==0) return;
            vis[i]=1;
        for(auto it:adj[i]){
            par.insert(it);
            filldata(par,vis,adj,it);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            set<int>par;
            filldata(par,vis,adj,i);
            vector<int>num(par.begin(),par.end());
            ans[i]=num;
           
        }
        return ans;
    }
};