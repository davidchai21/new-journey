class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        if (S.empty()) return res;
        int count = 0;
        int start = 0;
        for (int i=0;i<S.size();i++) {
            if (S[i]=='(') count++;
            else count--;
            if (count == 0) {
                res += S.substr(start+1, i-start-1);
                start = i+1;
            }
        }
        return res;
    }
};