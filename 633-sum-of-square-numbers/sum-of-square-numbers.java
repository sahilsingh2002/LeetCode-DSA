class Solution {
    public boolean judgeSquareSum(int c) {
        long l = 0,r=(long)Math.sqrt(c);
        while(l<=r){
            long one = l*l;
            long two = r*r;
            long sum = one+two;
            if(sum==c) return true;
            else if(sum<c) l++;
            else r--;
        }
        return false;
    }
}