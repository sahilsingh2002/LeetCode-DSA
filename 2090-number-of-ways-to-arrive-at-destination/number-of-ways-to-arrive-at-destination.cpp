#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<ll,vector<pair<ll,ll>>>adj;
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        int modd = 1e9+7;
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); 
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; 
            for(auto [v, time] : adj[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % modd;
                }
            }
        }
        return ways[n-1];
    }
};