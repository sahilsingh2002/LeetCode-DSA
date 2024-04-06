class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stk;
        string ans = "";
        vector<int> rem;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (!stk.empty()) {
                char x = stk.top();
                if (c == ')' && x == '(') {
                    rem.pop_back();
                    stk.pop();
                    continue;
                }
            }
            if (c == '(' || c == ')') {
                stk.push(c);
                rem.push_back(i);
            }
        }

        int idx = 0;
        if (!rem.empty()) {
            for (int i = 0; i < s.size(); i++) {
                if (idx < rem.size() && i == rem[idx]) {
                    idx++;
                    continue;
                }
                ans += s[i];
            }
        } else {
            return s;
        }

        return ans;
    }
};