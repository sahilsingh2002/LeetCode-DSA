class Solution {
   
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]) return k;
        for(int i:arr){
            if(i<=k) k++;
            else return k;
        }
        return k;
    }
};