class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>freq;
        for(int i:hand){
            freq[i]++;

        }
        while(freq.size()>0){
            
            auto it = freq.begin();
            int num = it->first;
            for(int i =0;i<groupSize;i++){
                if(freq[num+i]>0){
                    freq[num+i]--;
                    if(freq[num+i]==0){
                        auto it = freq.find(num+i);
                        freq.erase(it);
                    }
                }
                else return false;
            }
        }
        return true;
    }
};