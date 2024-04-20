class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
    vector<vector<int>> vis(land.size(), vector<int>(land[0].size(), 0));
    queue<pair<int,int>> q;
    vector<int> drow = {0, 0, -1, 1};
    vector<int> dcol = {1, -1, 0, 0};
    
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (land[i][j] == 1 && !vis[i][j]) {
                int minr = i, minc = j, maxr = i, maxc = j;
                q.push({i, j});
                vis[i][j] = 1;
                
                while (!q.empty()) {
                    auto x = q.front();
                    q.pop();
                    int r = x.first;
                    int c = x.second;
                    minr = min(minr, r);
                    maxr = max(maxr, r);
                    minc = min(minc, c);
                    maxc = max(maxc, c);
                    
                    for (int k = 0; k < 4; k++) {
                        int row = r + drow[k];
                        int col = c + dcol[k];
                        
                        if (row >= 0 && row < land.size() && col >= 0 && col < land[0].size() && land[row][col] == 1 && !vis[row][col]) {
                            q.push({row, col});
                            vis[row][col] = 1;
                        }
                    }
                }
                ans.push_back({minr, minc, maxr, maxc});
            }
        }
    }
    return ans;
    }
};