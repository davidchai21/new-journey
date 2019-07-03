class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0;
        int cur = 0;
        int res = 0;
        int i=0;
        while (i<s.size()) {
            int j=i+1;
            while (j<s.size() && s[j]==s[i]) j++;
            if (!cur) cur = j-i;
            else {
                pre = cur;
                cur = j-i;
                res += min(pre, cur);
            }
            i = j;
        }
        return res;
    }
};