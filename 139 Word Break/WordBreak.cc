class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (string a:wordDict) st.insert(a);
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for (int i=0;i<s.size();i++) {
            for (int j=i;j>=0;j--) {
                string t = s.substr(i-j,j+1);
                if (dp[i-j] && st.find(t)!=st.end()) {
                    dp[i+1]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};