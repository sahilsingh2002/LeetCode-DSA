class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int l =1;
        int r = nums.back();
        
        int ans =INT_MAX;
        while(l<=r){
            int sum2 = 0;
            int mid = l+(r-l)/2;
            for(int i=0;i<nums.size();i++){
                sum2+=(nums[i]/mid)+(nums[i]%mid>0?1:0);
            }
            if(sum2<=threshold){
                ans = mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
    return ans;
    }

};