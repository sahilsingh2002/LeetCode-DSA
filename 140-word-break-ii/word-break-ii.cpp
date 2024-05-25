class Solution {
    void solve(string s,vector<string>&wordDict,vector<vector<string>>&alls,vector<string>&curr,int i,int past){
        if(i>=s.size()){
            int p=0;
            for(string i:curr){
                p+=i.size();

            }
            if(p==s.size()){
                alls.push_back(curr);
            }
            return;
        }
            string a = s.substr(past,i-past+1);
            // cout<<a<<endl;
            auto itr = find(wordDict.begin(),wordDict.end(),a);
            if(itr!=wordDict.end()){
               
                curr.push_back(a);
                
                solve(s,wordDict,alls,curr,i+1,i+1);
                curr.pop_back();
                solve(s,wordDict,alls,curr,i+1,past);

            }
            else{
                solve(s,wordDict,alls,curr,i+1,past);
            }

    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>>alls;
        vector<string>curr;
        solve(s,wordDict,alls,curr,0,0);
        vector<string>ans;
        for(auto i:alls){
            string here = "";
            for(auto x:i){
                here+=x;
                here+=" ";
            }
           ans.push_back(here.substr(0,here.size()-1));
        }
        return ans;
    }
};