class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = t.back();
        for (int i=0;i<s.size();i++) {
            res ^= s[i];
            res ^= t[i];
        }
        return (char)res;
    }
};