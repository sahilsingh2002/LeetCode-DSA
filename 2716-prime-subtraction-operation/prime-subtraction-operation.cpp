class Solution {

public:
    vector<bool> is_prime;

    Solution() {
        is_prime.assign(1001, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= 1000; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums[0]-1; i >= 0; i--) {
            if (is_prime[i]) {
                ans.push_back(nums[0] - i);
                break;
            }
        }
        if (ans.size() == 0) {
            ans.push_back(nums[0]);
        }
        int curr = ans[0];

        for (int i = 1; i < nums.size(); i++) {
            int here = nums[i];
            for (int j = nums[i] - 1; j >= 0; j--) {
                if (is_prime[j] && nums[i] - j > curr) {

                    cout<<j<<endl;
                    here = nums[i] - j;
                    break;
                }
            }

            ans.push_back(here);
            curr = here;
        }
        for (int i = 0; i < ans.size() - 1; i++) {
            
            if (ans[i] >= ans[i + 1])
                return false;
        }
        return true;
    }
};