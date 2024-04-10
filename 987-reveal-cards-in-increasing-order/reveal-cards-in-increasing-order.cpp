class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int>ans(deck.size(),-1);
        queue<int>q;
        for(int i:deck) q.push(i);
            bool valid = true;
        while(!q.empty()){
            for(int i=0;i<deck.size();i++){
                if(ans[i]==-1){
                    if(valid){
                        int top = q.front();
                        q.pop();
                        ans[i]=top;
                        valid=false;
                    }
                    else{
                        valid = true;
                    }
                }
            }
        }
        return ans;
       
    }
};