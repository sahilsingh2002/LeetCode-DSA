class Solution {
public:
    vector<string> fullJustify(vector<string>& A, int B) {
        vector<string> ans;
    int n = A.size();
    int i = 0;
    
    while (i < n) {
        int start = i;
        int len = 0;
        
        while (i < n && len + A[i].size() + (i - start) <= B) {
            len += A[i].size();
            i++;
        }
        
        int numWords = i - start;
        int totalSpaces = B - len;
        int avgSpaces = numWords > 1 ? totalSpaces / (numWords - 1) : totalSpaces;
        int extraSpaces = numWords > 1 ? totalSpaces % (numWords - 1) : totalSpaces;

        string line = A[start];
        
       
        if (numWords == 1 && i < n) {
            line += string(B - len, ' ');
        } else {
            for (int j = start + 1; j < i; j++) {
                if(i==n){
                line+=' ';
            }
            else{
               
            line += string(avgSpaces, ' ');
            if (extraSpaces > 0) {
                line += " ";
                extraSpaces--;
             
            }
            }
            line += A[j];
            }
        }
        
       
        if (i == n) {
            line += string(B - line.size(), ' ');
        }
        
        ans.push_back(line);
    }
    
    return ans;
    }
};