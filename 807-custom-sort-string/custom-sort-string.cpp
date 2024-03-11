class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>freq;
        for(char i : order){
            for(char p : s){
                if(i==p){
                    freq[i]++;
                }
            }
        }
        string ans = "";
        for(char i :order){
            if(freq.find(i)!=freq.end()) {
                for(int j = 0;j<freq[i];j++){
                    ans+=i;
                }
            };
        }
        for(char i : s){
            if(freq.find(i)==freq.end()){
                ans+=i;
            }
        }
        return ans;
    }
};