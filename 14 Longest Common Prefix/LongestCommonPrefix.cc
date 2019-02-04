class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = strs[0];
        for (int i=1;i<strs.size();i++) {
            res = helper(res, strs[i]);
        }
        return res;
    }
    
    string helper(string a, string b) {
        int i = 0;
        while (i<a.size() && i<b.size()) {
            if (a[i] != b[i]) break;
            i++;
        }
        return a.substr(0,i);
    }
};