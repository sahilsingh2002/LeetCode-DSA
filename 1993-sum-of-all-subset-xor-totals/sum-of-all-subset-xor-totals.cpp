class Solution {
public:
void makesub(vector<vector<int>>&ans,vector<int>&subs,int idx,vector<int>& nums){
    ans.push_back(subs);
    for(int i=idx;i<nums.size();i++){
        subs.push_back(nums[i]);
        makesub(ans,subs,i+1,nums);
        subs.pop_back();
    }
}
    vector<vector<int>>allSub(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int>subs;
        int idx = 0;
        makesub(ans,subs,idx,nums);
        return ans;
    }

    int subsetXORSum(vector<int>& nums) {
       vector<vector<int>>subsets = allSub(nums);
       int sum = 0;
    for(auto it:subsets){
        if(it.size()==0) continue;
        int num = it[0];
        int idx = 1;
        while(idx<it.size()){
            num=num^it[idx];
            idx++;
        }
        sum+=num;
    }
        return sum;
    }
};