class Solution {
public:
    int scoreOfString(string s) {
        int n = 0;
        for(int i=0;i<s.size()-1;i++){
            n+=(abs(s[i]-s[i+1]));
        }
        return n;
    }
};