class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string initial = "0000";
        unordered_set<string>vis;
        unordered_set<string>deads(deadends.begin(),deadends.end());
        queue<pair<string,int>>q;
        q.push({initial,0});
        int cnt = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(vis.find(x.first)!=vis.end()) continue;
            vis.insert(x.first);
            if(deads.find(x.first)!=deads.end()) continue;
            if(x.first==target) return x.second;
            string curr = x.first;
            int moves = x.second;
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (curr[i] - '0' + delta + 10) % 10;
                    string newCombination = curr;
                    newCombination[i] = '0' + newDigit;
                    
                    if (vis.find(newCombination) == vis.end() && deads.find(newCombination) == deads.end()) {
                        q.push({newCombination, moves + 1});
                    }
                }
            }
        }
        return -1;
        
    }
};