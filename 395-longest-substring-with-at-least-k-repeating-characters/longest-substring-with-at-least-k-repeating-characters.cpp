class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n==0 || n<k) return 0;
        if(k<=1) return n;
        vector<int>freq(26,0);
        for(char i:s){
            freq[i-'a']++;

        }
        int l = 0;
        while(l<n && freq[s[l]-'a']>=k){
            l++;
        }
        if(l>=n-1) return l;
        int a = longestSubstring(s.substr(0,l),k);
        while(l<n && freq[s[l]-'a']<k) l++;
       int b = l<n?longestSubstring(s.substr(l),k):0;
       return max(a,b);
    }
};