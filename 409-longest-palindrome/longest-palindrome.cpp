class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq(256,0);
        for(char i:s){
            freq[i]++;
        }
        int sizer = s.size();
        int ones = 0;
        for(int i:freq){
            if(i&1){
                ones++;
            }
        }
        if(ones>1){
            sizer-=ones-1;

        }
        if(sizer&1){
            return sizer;
        }
        else{
            return ones>0?sizer-1:sizer;
        }
    }
};