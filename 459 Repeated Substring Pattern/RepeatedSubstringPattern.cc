class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i=1;i<=n/2;i++) {
            if (n%i==0) {
                string t = "";
                string base = s.substr(0,i);
                for (int j=0;j<n/i;j++) t+=base;
                if (t==s) return true;
            }
        }
        return false;
    }
};