class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3) return false;
        int l =0;
        while(l<arr.size()-2){
            if(arr[l]&1 && arr[l+1]&1 && arr[l+2]&1) return true;
            l++;
        }
        return false;
    }
};