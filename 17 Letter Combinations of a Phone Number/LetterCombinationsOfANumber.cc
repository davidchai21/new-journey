class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        for (int i=0;i<digits.size();i++) {
            vector<string> t;
            for (int j=0;j<table[digits[i]-'2'].size();j++) {
                for (int k=0;k<res.size();k++) {
                    t.push_back(res[k] + table[digits[i]-'2'][j]);
                }
            }
            res = t;
        }
        return res;
    }
private:
    vector<string> table{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};