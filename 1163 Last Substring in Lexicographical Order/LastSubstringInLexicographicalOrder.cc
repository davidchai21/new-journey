class Solution {
public:
    string lastSubstring(string s) {
        int res = 0;
        int i=1;
        int n=s.size();
        while (i<n) {
            if (s[i]>s[res]) res=i;
            else if (s[i]==s[res]) {
                int original_i = i;
                int j=res;
                while (i<n && s[j]==s[i]) {
                    i++;
                    j++;
                }
                if (i==n) break;
                else {
                    if (s[i]>s[j]) {
                        res = original_i;
                        continue;
                    }
                }
            }
            i++;
        }
        return s.substr(res);
    }
};