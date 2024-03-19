class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    
        unordered_map<int,int>prefsum;
        int sum = 0;
        int len = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0?-1:1;
            if(sum==0){
                len = i+1;
                
            }
            else if(prefsum.find(sum)!=prefsum.end()){
                len = max(len,i-prefsum[sum]);

            }
            else {
                prefsum[sum] = i;
            }
        }
        return len;
        
        
    }
};