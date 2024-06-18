typedef pair<int,int> pi;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       int maxdiff = *max_element(difficulty.begin(),difficulty.end());
       vector<int>maxprof(maxdiff+1,0);
       for(int i=0;i<difficulty.size();i++){
        maxprof[difficulty[i]]=max(maxprof[difficulty[i]],profit[i]);
       }
       for(int i=1;i<=maxdiff;i++){
        maxprof[i]=max(maxprof[i],maxprof[i-1]);
       }
       int cnt = 0;
       for(int i:worker){
        if(i>=maxdiff){
            cnt+=maxprof[maxdiff];
        }
        else cnt+=maxprof[i];
       }
       return cnt;
    }
};