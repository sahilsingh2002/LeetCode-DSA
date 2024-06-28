
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>conn(n,0);
        for(auto it:roads){
            conn[it[0]]++;
            conn[it[1]]++;

        }
        sort(conn.begin(),conn.end());
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=(long long)conn[i]*(i+1);
        }
            
        return sum;
    }
};