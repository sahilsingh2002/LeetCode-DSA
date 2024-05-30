class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // int n = arr.size();
        // int ans =0;
        // for(int i=0;i<n;i++){
        //     int curr = arr[i];
        //     for(int j = i+1;j<n;j++){
        //         curr^=arr[j];
        //         if(curr==0){
        //             ans+=(j-i);
        //         }
        //     }
        // }
        // return ans;
        

        // other way
        arr.insert(arr.begin(),0);
        int ans = 0;
        int n = arr.size();
        for(int i=1;i<n;i++){
            arr[i]^=arr[i-1];

        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    ans+=(j-i-1);

                }
            }
        }
        return ans;
       
        
       
    }
};