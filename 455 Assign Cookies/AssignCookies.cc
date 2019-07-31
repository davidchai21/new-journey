class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        if (g.empty() || s.empty()) return res;
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int i = 0;
        int j = 0;
        while (i<g.size() && j<s.size()) {
            while (i<g.size() && g[i]>s[j]) i++;
            if (i>=g.size()) break;
            res++;
            i++;
            j++;
        }
        return res;
    }
};