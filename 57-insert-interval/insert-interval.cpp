class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        a.push_back(newInterval);
        sort(a.begin(),a.end());
        int i=0;
        while(i<a.size()-1){
            if(a[i][1]>=a[i+1][0]){
                a[i]={min(a[i][0],a[i+1][0]),max(a[i][1],a[i+1][1])};
                a.erase(a.begin()+i+1);
            }
            else{
                i++;
            }
        }
        return a;
    }
};