class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum = 0;
        vector<int> cost(s.size(),0);
        int start = 0;
        int res = 0;
        for (int i=0;i<s.size();i++) {
            int val = abs(s[i]-t[i]);
            cost[i]=val;
            sum += val;
            while (sum>maxCost) {
                sum -= cost[start++];
            }
            res = max(res, i+1-start);
        }
        return res;
    }
};