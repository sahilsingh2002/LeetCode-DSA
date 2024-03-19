class Solution {
    bool static cmp (vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
    
    int i=0;
    int darts = 0;
    int currdart = points[i][1];
    while(i<points.size()){
        if(points[i][1]>=currdart && points[i][0]<=currdart){
            i++;
        }
        else{
            darts++;
            currdart = points[i][1];
            i++;
        }
    }
    return darts+1;
    }
};