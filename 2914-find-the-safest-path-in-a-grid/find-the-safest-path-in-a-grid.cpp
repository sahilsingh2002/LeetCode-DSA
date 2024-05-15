class Solution {
    vector<int>drow={0,0,-1,1};
    vector<int>dcol={1,-1,0,0};

    bool isValid(vector<vector<bool>>&visited,int r,int c){
        if(r<0 || r>=visited.size() || c<0 || c>=visited[0].size() || visited[r][c]) return false;
        return true;
    }
    bool isSafe(vector<vector<int>>&distThief,int sf){
        int n = distThief.size();
        queue<pair<int,int>>q;
        if(distThief[0][0]<sf) return false;
        q.push({0,0});
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int r = x.first;
            int c = x.second;
            if(r==n-1 && c == n-1) return true;
            for(int i=0;i<4;i++){
                int newr = r+drow[i];
                int newc = c+dcol[i];
                if(isValid(visited,newr,newc)) {
                    if(distThief[newr][newc]<sf) continue;
                    visited[newr][newc]=true;
                    q.push({newr,newc});
                }
               
            }
        }
        return false;
    }


public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        
        vector<vector<bool>>visited(m,vector<bool>(m,false));
        vector<vector<int>>distThief(m,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    visited[i][j]=true;
                    q.push({i,j});

                }
            }
        }
        int len = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto x = q.front();
                q.pop();

                int r=x.first;
                int c =x.second;
                distThief[r][c]=len;
                for(int i=0;i<4;i++){
                    int newr = r+drow[i];
                    int newc = c+dcol[i];
                    if(!isValid(visited,newr,newc)) continue;
                    visited[newr][newc]=true;
                    q.push({newr,newc});
                    
                }
            }
            len++;
        }
        int l = 0,r=len;
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(isSafe(distThief,mid)){
                cout<<mid<<endl;
                
                ans = mid;
                l=mid+1;
            }
        else{
            r=mid-1;
        }
        }
       return ans;
        

    }
};