#define ll long long
class Solution {

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<ll, ll>>> adj(n); 
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        set<pair<ll,ll>>st;
        vector<ll>distS(n,INT_MAX);
        vector<ll>distE(n,INT_MAX);
        distS[0]=0;
        distE[n-1]=0;
        
        st.insert({0,0});
        while(!st.empty()){
            auto x = *(st.begin());
            ll wt = x.first;
            ll node = x.second;
            st.erase(x);
            for(auto i :adj[node]){
                ll weight = i.second;
                ll node2 = i.first;
                if(wt+weight<distS[node2]){
                    if(distS[node2]!=1000){
                        st.erase({distS[node2],node2});
                    }
                    distS[node2]=wt+weight;
                    st.insert({wt+weight,node2});
                }
            }
        }
        st.insert({0,n-1});
        while(!st.empty()){
            auto x = *(st.begin());
            ll wt = x.first;
            ll node = x.second;
            st.erase(x);
            for(auto i :adj[node]){
                int weight = i.second;
                int node2 = i.first;
                // cout<<weight<<" "<<node2<<endl;
                if(wt+weight<distE[node2]){
                    if(distE[node2]!=1000){
                        st.erase({distE[node2],node2});
                    }
                    distE[node2]=wt+weight;
                    st.insert({wt+weight,node2});
                }
            }
        }
        vector<bool>ans;
        for(ll i=0;i<n;i++){
            cout<<distS[i]<<" "<<distE[i]<<endl;
        }
        ll idx = 0;
        ll maxm = distS[n-1];
        for(auto it:edges){
            ll x = it[0];
            ll y = it[1];
            if(distS[x]+distE[y]+it[2]==maxm || distS[y]+distE[x]+it[2]==maxm){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
        }
        return ans;
    }
};