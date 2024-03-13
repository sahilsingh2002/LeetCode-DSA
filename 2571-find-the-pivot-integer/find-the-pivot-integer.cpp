class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = n*(n+1)/2;
        int sum2=n;
        while(sum1>sum2 && n>0){
            sum1-=n;
            sum2+=n-1;
            n--;
        }
        return sum1==sum2?n:-1;
    }
};