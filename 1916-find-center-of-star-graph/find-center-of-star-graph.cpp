class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>nodes;
        unordered_map<int,vector<int>>edg;
        for(auto it:edges){
            edg[it[0]].push_back(it[1]);
            edg[it[1]].push_back(it[0]);
            nodes.insert(it[0]);
            nodes.insert(it[1]);
        }
        int n = nodes.size();
        for(auto it:edg){
            if(it.second.size()==n-1) return it.first;
        }
        return -1;
    }
};