class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            while(!stk.empty()){
                char top = stk.top();
                if(abs(s[i]-top)==32){
                    stk.pop();
                    i++;
                }
                else{
                    break;
                }
            }
            if(i<s.size()){

            stk.push(s[i]);
            }
            
        }
        string ans="";
        while(!stk.empty()){
            char c = stk.top();
            ans=c+ans;
            stk.pop();
        }
        return ans;
    }
};