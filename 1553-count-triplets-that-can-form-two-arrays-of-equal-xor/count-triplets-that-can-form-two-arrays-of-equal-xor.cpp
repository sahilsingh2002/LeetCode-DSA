class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt =0;
        for(int i=0;i<n-1;i++){
            int x = 0;
            for(int j=i;j<n-1;j++){
                x^=arr[j];
                int a = 0;
                for(int k=j+1;k<n;k++){
                    a^=arr[k];
                    if(x==a){
                        cnt++;
                    }
                }

            }
        }
        return cnt;
    }
};