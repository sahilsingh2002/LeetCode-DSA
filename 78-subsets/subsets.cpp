class Solution {
public:
// void subs(vector<int>&nums,vector<vector<int>>&ans,int i,vector<int>&sub){
//     if(i>=nums.size()) {
//         ans.push_back(sub);
//         return;
//     };
//     sub.push_back(nums[i]);
//     subs(nums,ans,i+1,sub);
//     sub.pop_back();
//     subs(nums,ans,i+1,sub);

// }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // vector<vector<int>>ans;
        // vector<int>sub;
        //  subs(nums,ans,0,sub);
        //  return ans;
        vector<vector<int>>ans={{}};
        for(int i:nums){
            int size = ans.size();
            for(int j=0;j<size;j++){
                vector<int>subset = ans[j];
                subset.push_back(i);
                ans.push_back(subset);
            }
        }
        return ans;
    }
};