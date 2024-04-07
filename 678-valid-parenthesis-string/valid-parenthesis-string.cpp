class Solution {
public:
    bool checkValidString(string s) {
        int minm =0, maxm =0;
        for(char c:s){
            if(c=='('){
                maxm++, minm++;
            } 
                if(c==')'){
                    maxm--,minm = max(minm-1,0);

                }
                if(c=='*'){
                    maxm++, minm = max(minm-1,0);
                }
                if(maxm<0) return false;
            
        }
        return minm == 0;
    }
};