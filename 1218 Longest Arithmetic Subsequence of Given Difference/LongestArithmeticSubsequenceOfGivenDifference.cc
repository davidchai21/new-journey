class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int res = 0;
        for (int a:arr) {
            int target = a-difference;
            if (m.find(target)!=m.end()) {
                m[a] = m[target] +1;
            } else {
                m[a]=1;
            }
            res = max(res, m[a]);
        }
        return res;
    }
};