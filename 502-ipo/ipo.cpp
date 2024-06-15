class Solution {
    typedef pair<int,int> pi;
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pi>profcap;
        for(int i=0;i<capital.size();i++){
            profcap.push_back({capital[i],profits[i]});
        }
        sort(profcap.begin(),profcap.end(),greater<pi>());
        priority_queue<int>pq;
        while(k--){

            while(profcap.size()>0 && profcap.back().first<=w){
                pq.push(profcap.back().second);
                
                profcap.pop_back();
            }
            if(pq.empty()) return w;
            w+=pq.top();
            
            pq.pop();
        }
        return w;
    }
};