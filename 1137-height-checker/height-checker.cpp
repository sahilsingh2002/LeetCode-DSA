class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>h;
        for(int i:heights){
            h.push_back(i);
        }
        sort(h.begin(),h.end());
        int cnt = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=h[i]) cnt++;
        }
        return cnt;
    }
};