class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int maxfreq=0;
        int count=0;
        for(int i:nums){
            freq[i]++;
            maxfreq=max(maxfreq,freq[i]);
        }
        for(auto i:freq){
            if(i.second==maxfreq){
                count++;
            }
        }
        
        return count*maxfreq;
    }
};