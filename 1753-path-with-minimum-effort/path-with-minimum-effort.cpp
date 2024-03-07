class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        if(m==1 && n==1) return 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({0,0,0});
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        vector<int>drow = {0,0,-1,1};
        vector<int>dcol = {1,-1,0,0};
        while(!q.empty()){
            auto vec1 = q.top();
            q.pop();
            int wt = vec1[0];
            int x = vec1[1];
            int y = vec1[2];
            if(x==m-1 && y==n-1) return wt;
            for(int i=0;i<4;i++){
                int r = x+drow[i];
                int c = y + dcol[i];
                if(r>=0 && r<m && c>=0 && c<n){
                      int newEffort = max(abs(heights[r][c] - heights[x][y]), wt);
                   
                    if(newEffort<dist[r][c]){
                        dist[r][c]=newEffort;
                        q.push({newEffort,r,c});
                    }
                }
            }
        }
        return 0;
    }
};