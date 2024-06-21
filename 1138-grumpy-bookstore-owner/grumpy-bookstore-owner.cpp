class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int maxc = 0;
        int n = grumpy.size();
        for(int i=0;i<n;i++){
            if(!grumpy[i]){
                sum+=customers[i];
            }
        }
        maxc = sum;
        int l = 0;
        while(l<n && !grumpy[l]){
            l++;
        }
        for(int i=l;i<min(n,l+minutes);i++){
            if(grumpy[i]){
                sum+=customers[i];
            }
        }
        maxc = max(sum,maxc);
        int r = l+minutes-1;
        while(r<n){
            if(grumpy[l]){
                sum-=customers[l];
            }
            l++;
            r++;
            if(r<n && grumpy[r]){
                sum+=customers[r];
            }
            maxc = max(sum,maxc);
        }
        return max(sum,maxc);
    }
};