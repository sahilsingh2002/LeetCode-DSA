typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        ll sum = 0;
        ll minm = INT_MAX;
        ll cnt = 0;
        for (auto i : nums) {
            if ((i ^ k) > i) {
                sum += (i ^ k);
                minm = min(minm, (ll)(i ^ k) - i);
                cnt++;
            } else {
                sum += i;
                minm = min(minm, (ll)(i - (i ^ k)));
            }
        }
        return cnt & 1 ? sum - minm : sum;
    }
};