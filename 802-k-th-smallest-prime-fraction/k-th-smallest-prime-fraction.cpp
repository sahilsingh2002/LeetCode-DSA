typedef pair<double,vector<int>> pi;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pi>fractions;
        for(int i=0;i<arr.size()-1;i++){
            for(int j = i+1;j<arr.size();j++){
                fractions.push_back({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                // cout<<fractions[fractions.size()-1].first<<endl;
            }
        }
        sort(fractions.begin(),fractions.end());
        return fractions[k-1].second;

    }
};