class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        
        unordered_map<string,int>ans;

        for(int i=0;i<s.size()-9;i++){
            string a = s.substr(i,10);

            ans[a]++;
        }
        vector<string>res;
       for(auto it:ans){
        if(it.second>1){
            res.push_back(it.first);
        }
       }
       return res;
    }
};