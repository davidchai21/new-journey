class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(S, 0, res);
        return res;
    }
    
    void helper(string s, int pos, vector<string>& res) {
        res.push_back(s);
        for (int i=pos; i<s.size();i++) {
            if (!isdigit(s[i])) {
                s[i] = toggle(s[i]);
                helper(s, i+1, res);
                s[i] = toggle(s[i]);
            }
        }
    }
    
    char toggle(char c) {
        if (c>='a' && c<='z') return c-'a'+'A';
        return c-'A'+'a';
    }
};