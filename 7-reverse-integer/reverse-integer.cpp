class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        string s=to_string(x);
    
        int p=s.size();
        if(x<pow(-2,31)||x>=pow(2,31)-1){
            return 0;
        }
        // cout<<pow(2,31)-1;
        // for(int i=0;i<p/2;i++){
        //     swap(s[i],s[p-i-1]);
        // }
        // long long m = stoi(s);
        // if(x<0){
        //     return m*-1;
        // }
        // return m;
        for(char c:s){
            if(c=='-'){
                continue;
            }
            rev+=(c-'0')*pow(10,s.size()-p);
            p--;
        }
        if(rev<pow(-2,31)||rev>=pow(2,31)-1){
            return 0;
        }
        if(x<0){
            return rev*-1;
        }
        else{
            return rev;
        }
    }
};