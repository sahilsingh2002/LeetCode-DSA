class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // Approach 2 specific if all given are stars
        int i=edges[0][0];
        int j = edges[0][1];
        return (edges[1][0]==i || edges[1][1]==i?i:j);


    }
};
        // approach 1 - general approach
        // unordered_set<int>nodes;
        // unordered_map<int,vector<int>>edg;
        // for(auto it:edges){
        //     edg[it[0]].push_back(it[1]);
        //     edg[it[1]].push_back(it[0]);
        //     nodes.insert(it[0]);
        //     nodes.insert(it[1]);
        // }
        // int n = nodes.size();
        // for(auto it:edg){
        //     if(it.second.size()==n-1) return it.first;
        // }
        // return -1;