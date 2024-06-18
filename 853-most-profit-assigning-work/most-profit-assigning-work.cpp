typedef pair<int,int> pi;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pi>vc;
        int n = difficulty.size();
        for(int i=0;i<n;i++){
            vc.push_back({difficulty[i],profit[i]});
        }
        sort(vc.begin(),vc.end());
        sort(worker.begin(),worker.end());
        int total = 0;
        int idx = 0;
        priority_queue<pi>pq;
        for(int i:worker){
            while(idx<n){
                if(i>=vc[idx].first){
                    pq.push({vc[idx].second,vc[idx].first});
                    idx++;
                }
                else break;
            }
            if(!pq.empty()){

            total+=pq.top().first;
            }
        }
        return total;
    }
};