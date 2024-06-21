class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int extra = 0;
        int maxExtra = 0;
        int n = grumpy.size();
        for(int i=0;i<n;i++){
            if(!grumpy[i]){
                sum+=customers[i];
            }
        }
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                extra+=customers[i];
            }
        }
        maxExtra = extra;
       for(int i=minutes;i<n;i++){
        if(grumpy[i-minutes]){
            extra-=customers[i-minutes];
        }
        if(grumpy[i]){
            extra+=customers[i];
        }
        maxExtra = max(extra,maxExtra);
       }
       return sum+maxExtra;
    }
};