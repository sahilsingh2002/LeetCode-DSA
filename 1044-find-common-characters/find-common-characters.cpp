class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>letters;
        for(int i=0;i<words[0].size();i++){
            // cout<<i<<endl;
            vector<int>idx;
            bool in = true;
            for(int j=1;j<words.size();j++){
                auto itr = words[j].find(words[0][i]);
                if(itr==string::npos){
                    in = false;
                    break;
                }
                
                else idx.push_back(itr);
                // cout<<j<<" "<<itr<<endl;
            }
            if(in){
                string x = "";
                x+=words[0][i];
                
                letters.push_back(x);
                for(int i=0;i<idx.size();i++){
                    
                    words[i+1][idx[i]]='*';
                }
               
            }
        }
       
        return letters;
    }
};