class Solution {
public:
    string addStrings(string num1, string num2) {
    
        int carry = 0;
        int l = num1.size()-1;
        int r = num2.size()-1;
        string ans = "";
        while(l>=0 && r>=0){
            int a = (num1[l]-'0');
            int b = (num2[r]-'0');
            int c = a+b+carry;
            if(c>=10){
                carry = c/10;
                c = c%10;
            }
            else{
                carry = 0;
            }
            ans = to_string(c)+ans;
            l--;
            r--;

        
        }
        
        while(l>=0){
            if(carry>0){
                int c = (num1[l]-'0');
                c+=carry;
                carry =0;
                if(c>=10){
                      carry = c/10;
                c = c%10;
                }
                 else{
                carry = 0;
            }
            ans = to_string(c)+ans;

            }
            else{
                ans= num1[l]+ans;
            }
            l--;
        }
        while(r>=0){
            if(carry>0){
                int c = (num2[r]-'0');
                c+=carry;
                carry =0;
                if(c>=10){
                      carry = c/10;
                c = c%10;
                }
                 else{
                carry = 0;
            }
            ans = to_string(c)+ans;

            }
            else{
                ans= num2[r]+ans;
            }
            r--;
        }
        return carry>0?to_string(carry)+ans:ans;
    }
};