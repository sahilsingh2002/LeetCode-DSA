class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int i:nums1){
            freq[i]++;
        }
        vector<int>num;
        for(int i:nums2){
            if(freq[i]>0){
                num.push_back(i);
            }

        }
        set<int>p(num.begin(),num.end());
        return{p.begin(),p.end()};
    }
};