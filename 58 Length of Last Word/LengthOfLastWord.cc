class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        bool flag = false;
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i]!=' ') {
                if (!flag) flag = true;
                res++;
            } else {
                if (flag) break;
            }
        }
        return res;
    }
};