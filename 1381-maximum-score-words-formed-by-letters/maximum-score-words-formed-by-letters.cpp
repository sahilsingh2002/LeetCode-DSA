class Solution {
public:
    int solve(vector<string>& words, unordered_map<char,int>&freq, vector<int>& score,int i){
        if(i>=words.size()) return 0;
        string x = words[i];
        string removed = "";
        int a = 0;
        for( char i :x){
            if(freq.find(i)!=freq.end() && freq[i]>0){
                removed+=i;
                // cout<<i<<" "<<freq[i]<<endl;
                freq[i]--;
                a+=score[i-'a'];
            } 
            else{
                a=0;
                for(char j:removed){
                    freq[j]++;
                }
                removed = "";
                break;
            }
        }
        // cout<<a<<" "<<words[i]<<endl;
        a+=solve(words,freq,score,i+1);
        for(char i:removed){
            freq[i]++;
        }
        removed = "";
        int b = solve(words,freq,score,i+1);
        return max(a,b);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>freq;
        for(char i:letters){
            freq[i]++;
        }
        return solve(words,freq,score,0);
    }
};