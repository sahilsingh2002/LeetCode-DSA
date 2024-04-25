class Solution {
    // int help(string &s,int k,int i,int a,vector<vector<int>>&dp){
    //     if(i>=s.size()) return 0;
    //     if(dp[i][a]!=-1) return dp[i][a];
    //     int op1=0;
    //     if(a==0 || abs(a-s[i])<=k){
    //         op1 = 1+help(s,k,i+1,s[i],dp);
    //     }
    //     int op2 = help(s,k,i+1,a,dp);
    //         cout<<op1<<" "<<op2<<endl;
    //     return dp[i][a]=max(op1,op2);
    // }
public:
    int longestIdealString(string s, int k) {
       vector<int>dp(256,0);

        // return help(s,k,0,0,dp);
        int ans = 0;
        for(auto i:s){
            for(int j=i-k;j<=i+k;j++){
                dp[i]=max(dp[i],dp[j]);
            }
            dp[i]++;
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};