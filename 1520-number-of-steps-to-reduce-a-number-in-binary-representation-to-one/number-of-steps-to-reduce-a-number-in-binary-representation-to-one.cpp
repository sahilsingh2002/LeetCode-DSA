class Solution {
public:
    int numSteps(string s) {
        vector<int>ones;
        vector<int>zeros;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zeros.push_back(i);

            }
            else{
                ones.push_back(i);
            }
        }
        int r = s.size()-1;
        int cnt = 0;
        while(r>=0){

            if(s[r]=='1' && s.size()>1){
                
                
                s[r]='0';
                if(zeros.size()>0){
                int p = zeros[zeros.size()-1];
                zeros.pop_back();
                // cout<<p<<endl;
                while(r>p){
                    s[r]='0';
                    r--;
                }
                s[r]='1';
                cnt++;
                cnt+=s.size()-(r+1);
                s=s.substr(0,r+1);
                // cout<<s<<endl;
                }
                else{
                    cnt+=s.size()+1;
                    return cnt;
                }
            }
            else if(s[r]=='1' && s.size()==1) return cnt;
            else{
                s =s.substr(0,r);
                // cout<<s<<endl;
                zeros.pop_back();
                r--;
                cnt++;
            }
            // cout<<"r"<<r<<endl;
        }
        return cnt;
    }
};