class Solution {
    bool isVow(char i){
return i=='a' || i=='o' || i=='e' || i=='i' || i=='u';
    }
public:
    int maxVowels(string s, int k) {
        int numvov = 0;
        if(k>=s.size()){
            for(int i:s){
                if(isVow(i)){
                    numvov++;
                }
                
            }
            return numvov;
        }
        int maxvov = 0;
        for(int i=0;i<k;i++){
             if(isVow(s[i])){
                    numvov++;
                }
        }
        maxvov = numvov;
        int l=0,r=k-1;
        while(r<s.size()){
            r++;
            if(isVow(s[r])){
                numvov++;
            }
            if(isVow(s[l])){
                numvov--;
            }
            l++;
            maxvov = max(maxvov,numvov);
        }
        return maxvov;
    }
};