class Solution {
    bool canplace(vector<int>&position,int m,int mid){
        int prev = position[0];
        int cnt = 1;
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=mid){
                prev = position[i];
                cnt++;
            }
        }
        return cnt>=m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
       
           int l = 1;
           int r =(position.back() - position[0]) / (m - 1);
            int ans = 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(canplace(position,m,mid)){
                ans = mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};