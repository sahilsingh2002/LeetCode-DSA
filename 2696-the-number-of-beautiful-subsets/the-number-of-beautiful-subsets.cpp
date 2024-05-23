class Solution {
    int solve(vector<int>& nums, int k, int i, vector<int>& num) {
        if (i >= nums.size())
            return 0;
        num.push_back(nums[i]);
        int x = nums[i] + k;
        int a = 0;
        if (find(num.begin(), num.end(), nums[i] + k) == num.end() &&
            find(num.begin(), num.end(), nums[i] - k) == num.end()) {
                
            a = 1+solve(nums, k, i + 1, num);
        }
        num.pop_back();
        int b = solve(nums, k, i + 1, num);
        return a + b;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> num;
        return solve(nums, k, 0, num);
    }
};