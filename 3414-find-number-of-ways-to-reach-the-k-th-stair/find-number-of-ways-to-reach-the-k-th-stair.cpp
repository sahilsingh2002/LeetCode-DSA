class Solution {
    unordered_map<int,unordered_map<int,unordered_map<int,int>>>canjump;
    int solve(int i,int k,int down,int jump){
        if(i>k+1) return 0;
        if(canjump.count(i) && canjump[i].count(down) && canjump[i][down].count(jump)) return canjump[i][down][jump];
        int ans = (i==k);
        ans+=solve(i+(1<<jump),k,0,jump+1);
        if(i!=0 && !down){
            ans+=solve(i-1,k,1,jump);
        }
        return canjump[i][down][jump]=ans;

        
    }
public:
    int waysToReachStair(int k) {
        return solve(1,k,0,0);
    }
};