class Solution {
    vector<int>turnInt(string version1,int m){
        vector<int>splitter;
         int a = 0;
        while(true){
            auto it = version1.find('.',a);
            if(it==string::npos){
                string x = version1.substr(a,m-a);
                int as = stoi(x);
                splitter.push_back(as);
                break;
            }
            else{
                 string x = version1.substr(a,it);
                int as = stoi(x);
                splitter.push_back(as);
                a = it+1;
            }

        }
        return splitter;
    }
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        vector<int>splitter1 = turnInt(version1,m);
        vector<int>splitter2 = turnInt(version2,n);
        int i ;
        for(i=0;i<min(splitter1.size(),splitter2.size());i++){
            if(splitter1[i]>splitter2[i]){
                return 1;
            }
            else if(splitter1[i]<splitter2[i]){
                return -1;
            }
        }
      
            while(i<splitter1.size()){
                if(splitter1[i]!=0) return 1;
                i++;
            }
            while(i<splitter2.size()){
                if(splitter2[i]!=0) return -1;
                i++;
            }
        return 0;
    }
};