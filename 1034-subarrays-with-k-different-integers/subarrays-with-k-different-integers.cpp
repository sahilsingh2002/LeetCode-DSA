class Solution {
public:
int atm(vector<int>&nums,int k){
   unordered_map<int,int>freq;
        int cnt = 0;
        int l=0,r=0;
        int n = nums.size();
        while(r<n){
            freq[nums[r]]++;
           
            while(freq.size()>k ){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return atm(nums,k)-atm(nums,k-1);
    }
};