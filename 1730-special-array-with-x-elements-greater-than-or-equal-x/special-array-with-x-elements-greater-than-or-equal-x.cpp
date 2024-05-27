class Solution {
public:
    int specialArray(vector<int>& nums) {
       vector<int>bucket(1001,0);
       for(int i:nums){
        bucket[i]++;
       }
       int tots = nums.size();

       for(int i=0;i<1001;i++){
        if(tots==i) return tots;
        tots-=bucket[i];
       }
       return -1;
        
    }
};