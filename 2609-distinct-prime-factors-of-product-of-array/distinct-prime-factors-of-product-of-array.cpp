class Solution {
bool isPrime(int n){
    if(n == 1 || n == 0)return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return false;
    }
    return true;
}
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int maxm = INT_MIN;
        for(int i:nums){
            maxm = max(maxm,i);
        }
        int cnt = 0;
        vector<int>allPrimes;
        for(int i=2;i<=maxm;i++){
            if(isPrime(i)){
                allPrimes.push_back(i);
            }
        }
        for(int i:allPrimes){
            bool divisible = false;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%i==0){
                    nums[j]/=i;
                    divisible = true;
                    break;
                }
            }
            cnt+=divisible;
        }
        return cnt;

    }
};