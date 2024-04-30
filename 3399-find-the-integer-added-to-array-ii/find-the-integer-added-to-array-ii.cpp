class Solution {
    bool check(vector<int>& nums1, vector<int>& nums2,int x){
        int missed = 0;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(missed>2) return false;
            if(nums2[j]-nums1[i]==x){
                i++;
                j++;
            }
            else{
                missed++;
                i++;
            }

        }

        return (missed<=2);
    }
    
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int ans = INT_MAX;
        for(int i=0;i<min(3,(int)nums1.size());i++){
            int x = nums2[0]-nums1[i];
            if(check(nums1,nums2,x)){
                ans = min(ans,x);
            }
        }
        return ans;
    }
};