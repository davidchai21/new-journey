class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        string segment = "";
        for (int i=S.size()-1;i>=0;i--) {
            if (S[i]=='-') continue;
            segment += (char)toupper(S[i]);
            if (segment.size() == K) {
                if (res == "") res = segment;
                else res += "-"+segment;
                segment = "";
            }
        }
        if (!segment.empty()) {
            if (res == "") res = segment;
            else res += "-"+segment;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};