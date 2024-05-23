class Solution {
    private int solve(int[] nums,int k,ArrayList<Integer> list,int i){
        if(i==nums.length) return 0;
        int p = nums[i];
        int a = 0;
        list.add(p);
        if(!list.contains(p+k) && !list.contains(p-k)){
            a = 1+solve(nums,k,list,i+1);
        }
        list.remove(list.size()-1);
        int b = solve(nums,k,list,i+1);
        return a+b;
    }
   
    public int beautifulSubsets(int[] nums, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        return solve(nums,k,list,0);
    }
}