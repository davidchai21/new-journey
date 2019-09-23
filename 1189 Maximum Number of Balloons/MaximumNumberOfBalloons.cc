class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> dic(26,0);
        for (char c:text) {
            dic[c-'a']++;
        }
        int res = INT_MAX;
        res = min(res, dic[0]);
        res = min(res, dic[1]);
        res = min(res, dic[11]/2);
        res = min(res, dic[14]/2);
        res = min(res, dic[13]);
        return res;
    }
};