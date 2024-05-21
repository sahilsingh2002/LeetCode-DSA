class Solution {
public:
void subs(vector<int>&nums,vector<vector<int>>&ans,int i,vector<int>&sub){
    if(i>=nums.size()) {
        ans.push_back(sub);
        return;
    };
    sub.push_back(nums[i]);
    subs(nums,ans,i+1,sub);
    sub.pop_back();
    subs(nums,ans,i+1,sub);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>ans;
        // for(int i=0;i<(1<<n);i++){
        //     vector<int>sub;
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j)){
        //             sub.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(sub);
        // }
        // return ans;
        vector<vector<int>>ans;
        vector<int>sub;
         subs(nums,ans,0,sub);
         return ans;
    }
};