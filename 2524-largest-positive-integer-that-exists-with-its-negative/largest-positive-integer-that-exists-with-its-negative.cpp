class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int l=0,r= nums.size()-1;
        // int maxm = INT_MIN;
        // while(l<r){
        //     if(nums[l]+nums[r]==0){
        //         return nums[r];
        //     }
        //     else if(nums[l]+nums[r]>0){
        //         r--;
        //     }
        //     else{
        //         l++;
        //     }
        // }
        // return -1;
        

        // approach 2
        unordered_set<int>idx(nums.begin(),nums.end());
        int maxm = INT_MIN;
        int id = 0;
        for(int i:nums){
            if(idx.find(0-i)!=idx.end()){
                maxm = max(maxm,abs(i));
            }
           
        }
        return maxm==INT_MIN?-1:maxm;
    }
};