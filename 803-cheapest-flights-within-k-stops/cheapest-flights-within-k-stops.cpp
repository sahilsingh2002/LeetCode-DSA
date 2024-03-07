class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto edge:flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        queue<vector<int>>pq;
        vector<int>dist(n,1e9);
        dist[src]=0;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto vec = pq.front();
            pq.pop();
            int wt = vec[0];
            int node = vec[1];
            int nowk = vec[2];
            for(auto it:adj[node]){
                if(wt+it.second<dist[it.first] && nowk<k+1){
                    dist[it.first]=wt+it.second;
                    pq.push({dist[it.first],it.first,nowk+1});
                }
            }
        }
        return dist[dst]!=1e9?dist[dst]:-1;
    }
};