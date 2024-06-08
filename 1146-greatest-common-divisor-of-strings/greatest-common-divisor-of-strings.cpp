class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string x = str1+str2;
        string y = str2+str1;
        if(x!=y) return "";
        int p = __gcd(str1.size(),str2.size());
        return str1.substr(0,p);
    }
};