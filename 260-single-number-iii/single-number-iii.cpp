typedef long long ll;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int num = 0;
       vector<int>ans;
       for(int i:nums){
        num^=i;

       }
       ll mask = (num&((ll)-1*num));
       int firstnum = 0;
    for(int i=0;i<nums.size();i++){
        if((mask&nums[i])==mask){
            firstnum^=nums[i];
        }
    }
    ans.push_back(firstnum);
    ans.push_back(num^firstnum);
    return ans;
    }
};