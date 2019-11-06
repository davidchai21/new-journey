class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int sum = s[0]=='L'?-1:1;
        for (int i=1;i<s.size();i++) {
            sum += s[i]=='L'?-1:1;
            if (sum == 0) ++res;
        }
        return res;
    }
};