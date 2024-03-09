class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int l =0,r=0;
        while(l<nums1.size() && r<nums2.size()){
            if(nums1[l]==nums2[r]) return nums1[l];
            else if(nums1[l]>nums2[r]) r++;
            else l++;
        }
        return -1;
    }
};