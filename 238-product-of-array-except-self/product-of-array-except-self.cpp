class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 0;
        int zer = 0;
        for(int num:nums){
            if(num!=0){
                if(prod==0) prod=num;
                else prod*=num;
            }
            else{
                zer++;
            }
        }
        vector<int>ans(nums.size(),0);
        if(zer){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    if(zer>1) continue;
                    ans[i]=prod;
                }
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};