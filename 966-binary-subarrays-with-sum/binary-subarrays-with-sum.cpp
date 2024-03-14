class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>freq;
        int total = 0;
        int curr = 0;
        for(int num : nums){
            curr+=num;
            if(curr == goal){
                total++;
            }
            if(freq.find(curr-goal)!=freq.end()){
                total+= freq[curr-goal];
            }
                freq[curr]++;
        }
    return total;
    }
};