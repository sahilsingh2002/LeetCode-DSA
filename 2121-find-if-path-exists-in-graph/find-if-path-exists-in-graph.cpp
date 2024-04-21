class Solution {
public:
    void dfs(vector<vector<int>>& adj, int root, int dest, vector<int>& visited){
        visited[root] = 1;
        if(root == dest) return;
        for(int i = 0; i < adj[root].size(); i++){
            int nxt = adj[root][i];
            if(!visited[nxt]) dfs(adj, nxt, dest, visited);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n,0);
        dfs(adj, source, destination, visited);
        return visited[destination];
    }
};