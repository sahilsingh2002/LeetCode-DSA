class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool>elements(2001,false);
        int ans = -1;
        for(int i:nums){
            if(elements[-i+1000]) ans = max(ans,abs(i));
            elements[i+1000]=1;
        }
    return ans;
    }

};