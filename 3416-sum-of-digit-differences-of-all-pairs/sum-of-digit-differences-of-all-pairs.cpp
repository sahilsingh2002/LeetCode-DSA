typedef long long ll;
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int size = to_string(nums[0]).size();
        vector<vector<int>>freq(size,vector<int>(10,0));
        for(int i:nums){
            string x = to_string(i);
            for(int idx=0;idx<size;idx++){
                freq[idx][x[idx]-'0']++;
            }
        }
        int n = nums.size();
        ll cnt = 0;
        for(int i=0;i<size;i++){
            for(int j=0;j<10;j++){
                if(freq[i][j]!=0){
                    cnt+=freq[i][j]*(n-freq[i][j]);
                }
            }
        }
        return cnt/2;
    }
};