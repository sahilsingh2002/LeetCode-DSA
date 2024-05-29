class Solution {
public:
    int numSteps(string s) {
        int size = s.size();
        int makezero = size-1,car = 0;
        for(int i=size-1;i>0;i--){
            if(s[i]-'0'+car==1){
                makezero++;
                car=1;
            }
        }
        return makezero+car;
    }
};