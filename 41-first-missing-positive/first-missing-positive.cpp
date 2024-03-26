class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s1(nums.begin(),nums.end());
        for(int i=1;i<=INT_MAX;i++){
            if(s1.find(i)==s1.end()) return i;
        }
        return 0;
    }
};