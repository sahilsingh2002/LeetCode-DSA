class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>allwords;
        string x = "";
        int idx =0;
        for(auto i:sentence){
            if(i==' '){
                if(x.size()>0){
                    allwords.push_back(x);
                    // cout<<x<<endl;
                    x="";
                    idx++;
                }
                continue;
            }
            x+=i;
            
            
        }
        if(x.size()>0){
            allwords.push_back(x);
            x="";
        }
        for(auto y:dictionary){
            int size = y.size();
            for( idx=0;idx<allwords.size();idx++){
                if(allwords[idx].substr(0,size)==y){
                    allwords[idx]=y;
                }
            }
        }
        for(auto y:allwords){
            cout<<y<<endl;
        }
         x = "";
        for(auto y:allwords){
            x+=y;
            x+=" ";
        }
        return x.substr(0,x.size()-1);
       

    }
};