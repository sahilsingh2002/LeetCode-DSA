class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans =0;
        int i= 0;
        while(i<word.size()){
            if(word[i]=='a'){
                if(i+1<n && word[i+1]=='b'){
                    if(i+2<n && word[i+2]=='c'){
                        i+=3;
                    }
                    else{

                    ans+=1;
                    i+=2;
                    }
                }
                else if(i+1<n && word[i+1]=='c'){
                    ans+=1;
                    i+=2;
                }
                else{
                ans+=2;
                i++;
                }
            }
            else if(word[i]=='b'){
                if(i+1<n && word[i+1]=='c'){
                    ans+=1;
                    i+=2;
                }
                else{
                    ans+=2;
                    i++;
                }
            }
            else{
                ans+=2;
                i++;
            }
        }
        return ans;
    }
};