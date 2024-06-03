class Solution {
public:
    int appendCharacters(string s, string t) {
        int idx = 0;
        for(char i:s){
            if(i==t[idx]){
                idx++;
            }
        }
        return t.size()-idx;
    }
};