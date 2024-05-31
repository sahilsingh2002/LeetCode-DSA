class Solution {
    public int[] singleNumber(int[] nums) {
        int ans[] = new int[2];
        int xor = 0;
        for(int i:nums){
            xor^=i;
        }
        int first = 0;
        int mask = (xor&(-1*xor));
        for(int i:nums){
            if((mask&i)==mask){
                first^=i;
            }
        }
        ans[0]=first;
        ans[1]=(first^xor);
        return ans;
    }
}