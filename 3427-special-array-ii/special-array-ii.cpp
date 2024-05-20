class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        if (n < 2) {
            return vector<bool>(queries.size(), true);
        }
        
        vector<int> par(n, 0);
        for (int i = 1; i < n ; i++) {
            if ((nums[i] & 1)!= (nums[i - 1] & 1)) {
                par[i] = 1;
            }
        }
        
        vector<int> pref(n , 0);
        pref[0] = par[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + par[i];
        }
        
        vector<bool> res;
        for (const auto& query : queries) {
            int a = query[0], b = query[1];
            if (a == b) {
                res.push_back(true);
            } else {
                int num = pref[b];
                if (a > 0) {
                    num -= pref[a];
                }
                res.push_back(num == (b - a));
            }
        }
        return res;
        
    }
};