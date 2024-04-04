class Solution {
public:
    int maxDepth(string s) {
        int maxt=0;
            int count=0;
        for(char i:s){
            if(i=='('){

                count++;
            }
            else if(i==')'){
                if(count>maxt){
                    maxt=count;
                }
                count--;
            }

        }
        return maxt;
    }
};