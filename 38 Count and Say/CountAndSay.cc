class Solution {
public:
    string countAndSay(int n) {
        if (n<=1) return "1";
        string s = countAndSay(n-1);
        int i = 0;
        string res = "";
        while (i<s.size()) {
            char p = s[i];
            int count = 0;
            while (i<s.size() && s[i]==p) {
                i++;
                count++;
            }
            res+=to_string(count)+p;
        }
        return res;
    }
};