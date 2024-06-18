class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<int[]>vc = new ArrayList<>();
        int n =difficulty.length;
        for(int i=0;i<n;i++){
            vc.add(new int[]{difficulty[i],profit[i]});
        }
        Collections.sort(vc,(a,b)->a[0]-b[0]);
        Arrays.sort(worker);
        PriorityQueue<int[]>maxprof = new PriorityQueue<>((a,b)->b[0]-a[0]);
        int total = 0;
        int idx = 0;
        for(int i:worker){
            while(idx<n && i>=vc.get(idx)[0]){
                maxprof.offer(new int[]{vc.get(idx)[1],vc.get(idx)[0]});
                idx++;
            }
            if(!maxprof.isEmpty()){
                total+=maxprof.peek()[0];
            }
        }
        return total;
    }
}