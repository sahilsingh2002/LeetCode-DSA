class Solution {
    bool isPalin(string &s,int i,int j) {
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string &s,int i,vector<vector<string>>&ans,vector<string>&way){
        if(i>=s.size()) {
            ans.push_back(way);
            return;
        }
        for(int j = i+1;j<=s.size();j++){
            if(isPalin(s,i,j-1)){
                way.push_back(s.substr(i,j-i));
                backtrack(s,j,ans,way);
                way.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>way;
        backtrack(s,0,ans,way);
        return ans;
    }
};