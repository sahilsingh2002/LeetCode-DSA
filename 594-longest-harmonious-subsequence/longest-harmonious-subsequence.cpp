class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int p = 0;
        for(int i:nums){
            mp[i]++;
        }
        for(int i:nums){
            if(mp[i]>0 && mp[i+1]>0){

            p=max(p,mp[i]+mp[i+1]);
            }
        }
        return p;
    }
};