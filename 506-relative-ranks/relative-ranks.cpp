class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>scorer;
        int n = score.size();
        for(int i=0;i<score.size();i++){
            scorer.push_back({score[i],i});
        }
        sort(scorer.begin(),scorer.end());
        reverse(scorer.begin(),scorer.end());
        vector<string>ans(score.size());
        ans[scorer[0].second]="Gold Medal";
        if(n>1) ans[scorer[1].second]="Silver Medal";
        if(n>2) ans[scorer[2].second]="Bronze Medal";
        for(int i=3;i<n;i++){
            ans[scorer[i].second] = to_string(i+1);
        }
        return ans;


    }
};