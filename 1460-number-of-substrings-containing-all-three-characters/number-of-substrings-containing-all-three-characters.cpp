class Solution {
public:
int atm(string &s,int k){
   unordered_map<char,int>freq;
        int cnt = 0;
        int l=0,r=0;
        int n = s.size();
        while(r<n){
            freq[s[r]]++;
           
            while(freq.size()>k ){
                freq[s[l]]--;
                if(freq[s[l]]==0){
                    freq.erase(s[l]);
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
}
    int numberOfSubstrings(string s) {
        return atm(s,3) - atm(s,2);
    }
};