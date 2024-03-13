class Solution {
public:
    int pivotInteger(int n) {
        int sum1 = n*(n+1)/2;
        // int sum2=n;
        // while(sum1>sum2 && n>0){
        //     sum1-=n;
        //     sum2+=n-1;
        //     n--;
        // }
        // return sum1==sum2?n:-1;
        int l = 1,h= n+1;
        while(l<h){
            int mid = l+(h-l)/2;
            int lsum = mid*(mid-1)/2;
            int hsum = sum1 - (mid+1)*mid/2;
            if(lsum<hsum){
                l = mid+1;
            }
            else h=mid;
        }
        return (l-1)*l/2==sum1-(l*(l+1)/2)?l:-1;
    }
};