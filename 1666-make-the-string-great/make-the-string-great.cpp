class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int idx=0;
        for(int i=1;i<s.size();i++){
            if(abs(s[i]-s[i-1])==32){
               
                s.erase(i-1,2);
                i=0;
            }
        }
       
       return s;
    }
};