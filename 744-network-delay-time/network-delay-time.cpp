class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      unordered_map<int,vector<pair<int,int>>>adj;
      for(auto it:times){
          adj[it[0]].push_back({it[1],it[2]});

      }  
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
      vector<int>dist(n+1,1e9);
      dist[k]=0;
      pq.push({0,k});
      while(!pq.empty()){
          auto x = pq.top();
          int wt = x[0];
          int u = x[1];
          pq.pop();
          for(auto it:adj[u]){
              int v = it.first;
              int weight = it.second;
              if(dist[v]>weight+wt){
                  dist[v]=weight+wt;
                  pq.push({dist[v],v});
              }
          }
      }
      int mamx = INT_MIN;
      for(int i=1;i<=n;i++){
          if(dist[i]==1e9) return -1;
          mamx = max(mamx,dist[i]);
      }
      return mamx;
    }
};