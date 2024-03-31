#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll mini = -1,maxi = -1, curi = -1;
        ll ans = 0;
        for(ll i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                curi = i;
            }
            if(nums[i]==minK) mini = i;
            if(nums[i]==maxK) maxi = i; 
            ans += max(0LL,min(mini,maxi)-curi);
        }

            

        return ans;
        

    }
};