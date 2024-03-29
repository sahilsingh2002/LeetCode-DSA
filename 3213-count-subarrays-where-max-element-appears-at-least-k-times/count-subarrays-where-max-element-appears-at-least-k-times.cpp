#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxm = INT_MIN;
        for(int i:nums){
            maxm = max(i,maxm);
        }
        int n = nums.size();
        ll freq=0;
        ll cnt=0;
        ll l=0,r=0;
        ll ans=0;
        while(r<n){
            if(nums[r]==maxm){
                freq++;
            }
            while(freq>=k){
                if(nums[l]==maxm){
                    freq--;
                }
                ans+=n-r;
                l++;
            }
            r++;
        }
        return ans;
    }
};