class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr1(1001,0);
        for(int i:nums1){
            arr1[i]++;

        }
        vector<int>ans;
        for(int i:nums2){
            if(arr1[i]>0){
                ans.push_back(i);
                arr1[i]--;
            }
        }
        return ans;
    }
};