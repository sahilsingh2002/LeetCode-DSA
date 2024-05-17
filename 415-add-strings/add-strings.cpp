class Solution {
public:
    string addStrings(string num1, string num2) {

        int carry = 0;
        int l = num1.size() - 1;
        int r = num2.size() - 1;
        string ans = "";

        while (l >= 0 || r >= 0 || carry > 0) {
            int a = (l >= 0) ? num1[l--] - '0' : 0;
            int b = (r >= 0) ? num2[r--] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            ans = to_string(sum % 10) + ans;
        }
        return ans;
    }
};