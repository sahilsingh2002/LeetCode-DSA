class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int l=0,r=0;
       vector<int>diff(s.size(),0);
       for(int i=0;i<s.size();i++){
        diff[i]=abs(s[i]-t[i]);
       }
       int maxc = 0;
        while(r<s.size()){
            if(diff[r]<=maxCost){
                maxCost-=diff[r];
                r++;
            }
            else{
                maxc = max(maxc,r-l);
                maxCost+=diff[l];
                l++;
            }
        }
        maxc = max(maxc,r-l);
        return maxc;
    }
};