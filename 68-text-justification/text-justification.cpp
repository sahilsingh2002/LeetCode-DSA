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
        
        int numwords = i - start;
        int totals = B - len;
        int avgsp = numwords > 1 ? totals / (numwords - 1) : totals;
        int remsp = numwords > 1 ? totals % (numwords - 1) : totals;

        string line = A[start];
        
       
        if (numwords == 1 && i < n) {
            line += string(B - len, ' ');
        } else {
            for (int j = start + 1; j < i; j++) {
                if(i==n){
                line+=' ';
            }
            else{
               
            line += string(avgsp, ' ');
            if (remsp > 0) {
                line += " ";
                remsp--;
             
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