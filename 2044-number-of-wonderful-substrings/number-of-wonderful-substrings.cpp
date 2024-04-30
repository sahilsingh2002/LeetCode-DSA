#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll>parity;
        ll ans = 0;
        ll pref = 0;
        parity[0]=1;
        for(auto c:word){
            pref = (pref^(1<<(c-'a')));
            ans+=parity[pref];
            for(auto x = 'a';x<='j';x++){
                ll oddpat = (pref^(1<<(x-'a')));
                ans+=parity[oddpat];

            }
            parity[pref]++;
        }
        return ans;
    }
};