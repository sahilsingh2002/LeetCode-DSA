class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        for(int i=0;i<=k;i++){
            cnt+=min(tickets[i],tickets[k]);
        }
        tickets[k]--;
        for(int i=k+1;i<tickets.size();i++){
            cnt+=min(tickets[i],tickets[k]);

        }
        return cnt;
    }
};