class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        vector<int>maxC(n,0);
        int minm= INT_MAX;
        int ans =-1;
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k = 0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][k]!=1e9 && dist[k][j]!=1e9){
                        dist[i][j]=min(dist[i][j],dist[i][k]+ dist[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
           
            for(int j:dist[i]){
                if(j<=distanceThreshold){
                    maxC[i]++;
                }
            }
        }
        for(int i:maxC){
            minm = min(minm,i);
        }
        for(int i=0;i<maxC.size();i++){
            if(maxC[i]==minm){
                ans = i;
            }
        }
        return ans;
    }
};