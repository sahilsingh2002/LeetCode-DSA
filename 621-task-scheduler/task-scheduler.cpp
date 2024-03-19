class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char i :tasks){
            freq[i-'A']++;
        }
        sort(freq.begin(),freq.end());
        int pack = freq[25]-1;
        int idle = pack*n;
        for(int i=24;i>=0;i--){
            idle-=min(freq[i],pack);
        }
        return idle<0?tasks.size():tasks.size()+idle;
    }
};