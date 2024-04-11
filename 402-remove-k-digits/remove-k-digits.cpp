class Solution {
    
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        for(char i:num){
            while(!stk.empty() && k>0 && stk.top()>i){
                stk.pop();
                k--;
            }
            if(!stk.empty() || i!='0') stk.push(i);

        }
        while(!stk.empty() && k>0) {
            stk.pop();
            k--;
        }
        string ans = "";
        while(!stk.empty()){
            ans +=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans.size()==0?"0":ans;
        
    }
};