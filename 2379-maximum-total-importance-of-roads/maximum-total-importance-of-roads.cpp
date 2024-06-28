
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>conn(n,0);
        vector<int>freq(n+1,0);
        for(auto it:roads){
            conn[it[0]]++;
            conn[it[1]]++;

        }
        for(int i:conn){
            freq[i]++;
        }

       
        long long sum = 0;
        long long curr = 1;
        int idx = 0;
        while(idx<=n){
            while(freq[idx]>0){
                sum+=(curr*idx);
                curr++;
                freq[idx]--;
            }
            idx++;
        }
            
        return sum;
    }
};