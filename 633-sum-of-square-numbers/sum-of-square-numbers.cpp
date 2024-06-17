class Solution {
    // vector<int>sqrs;

public:
    bool judgeSquareSum(int c) {
    //     int x = sqrt(INT_MAX);
        
    // for(int i=0;i<=x;i++){
    //     sqrs.push_back(i*i);
    // }    
    // int sizer = min(c,(int)sqrs.size());
    // if(c==0) return true;
    // for(int i=0;i<sizer;i++){

    //      int p = c-(sqrs[i]);
    //     int it = *lower_bound(sqrs.begin(),sqrs.end(),p);
        
    //     if(it==p) return true;
    // }
    // return false;
    // }
    for (int divisor = 2; divisor * divisor <= c; divisor++) {
            if (c % divisor == 0) {
                int exponentCount = 0;
                while (c % divisor == 0) {
                    exponentCount++;
                    c /= divisor;
                }
                if (divisor % 4 == 3 && exponentCount % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};