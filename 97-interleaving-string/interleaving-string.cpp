class Solution {
    // bool help(string s1,string s2,string s3,vector<vector<vector<int>>>&dp){
    //     if(s1.size()==0 && s2.size()==0 && s3.size()==0) return true;
    //     if(dp[s1.size()][s2.size()][s3.size()]!=-1) return dp[s1.size()][s2.size()][s3.size()];
    //     // if((s1.size()==0 && s2.size()==0) || s3.size()==0) return false;
    //     bool op1=false;
    //     bool op2 = false;

    //     if(s1[0]==s3[0]){
    //         op1 = true & help(s1.substr(1),s2,s3.substr(1),dp);
    //     } 
    //      if(s2[0]==s3[0]){
    //         op2 = true & help(s1,s2.substr(1),s3.substr(1),dp);
    //     }
    //     return dp[s1.size()][s2.size()][s3.size()] =op1 | op2;
        
    // }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
        dp[0][0][0]=1;
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                for(int k=1;k<=s3.size();k++){
                    if(i==0 && j==0) dp[i][j][k]=0;
                   else if(i==0){
                    dp[i][j][k]=(dp[i][j-1][k-1] & (s2[j-1]==s3[k-1]));
        
                   }
                    else if(j==0){
                    dp[i][j][k]=(dp[i-1][j][k-1] & (s1[i-1]==s3[k-1]));
                   }
                   else{
                    dp[i][j][k]=((dp[i-1][j][k-1]& s1[i-1]==s3[k-1]) | (dp[i][j-1][k-1]& s2[j-1]==s3[k-1]));
                   }
                }
            }
        }
        return dp[s1.size()][s2.size()][s3.size()];
    }
};