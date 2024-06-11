class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>freq(1001,0);
        for(int i:arr1){
            freq[i]++;
        }
        int idx=0;

        for(int i:arr2){
            while(freq[i]>0){
                arr1[idx]=i;
                idx++;
                freq[i]--;
            }
        }
        for(int i=0;i<freq.size();i++){
            while(freq[i]>0){
                arr1[idx]=i;
                idx++;
                freq[i]--;
            }
        }
        return arr1;
    }
};