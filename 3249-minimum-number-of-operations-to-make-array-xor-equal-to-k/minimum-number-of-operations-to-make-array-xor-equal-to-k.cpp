class Solution {
    string decToBinary(int n)
{
    string x = "";
   
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
           x+='1';
        else
            x+= '0';
    }
    return x;
}
public:
    int minOperations(vector<int>& nums, int k) {
        int x = nums[0];
        for(int i=1;i<nums.size();i++){
            x^=nums[i];
        }
        int cnt = 0;
        cout<<x<<endl;
       
        string a = decToBinary(x);
        string b = decToBinary(k);
        for(int i=0;i<=31;i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        return cnt;
    }
};