class Solution {
public:
    string customSortString(string order, string s) {
       vector<int>freq(26,0);
       string ans="";
       for(char i:s){
           freq[i-'a']++;
       }
       for(char i : order){
           while(freq[i-'a']){
               ans+=i;
               freq[i-'a']--;
           }
       }
       for(int i=0;i<freq.size();i++){
           while(freq[i]){
               ans+=i+'a';
               freq[i]--;
           }
       }
       return ans;
    }
};