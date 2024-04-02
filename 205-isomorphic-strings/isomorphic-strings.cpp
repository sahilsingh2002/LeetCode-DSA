class Solution {
public:
    bool isIsomorphic(string s, string t) {
      if(s.size()!=t.size()) return false;
      unordered_map<char,char>seens;
      unordered_map<char,char>seent;
        for(int i=0;i<s.size();i++){
            seens[s[i]]='0';
            seent[t[i]]='0';
            
        }
        for(int i=0;i<s.size();i++){
            if(seens[s[i]]!='0' || seent[t[i]]!='0'){
                if(seens[s[i]]!=t[i]){
                    // cout<<t[i]<<" "<<seen[s[i]]<<endl;
                    return false;
                }
                if(seent[t[i]]!=s[i]){
                    cout<<"heret"<<endl;
                     return false;
                }
            }
            seens[s[i]]=t[i];
            seent[t[i]]=s[i];
        }
        return true;
    }
};