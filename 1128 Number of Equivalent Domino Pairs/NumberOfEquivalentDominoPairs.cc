class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> m;
        for (vector<int> a:dominoes) {
            int x = min(a[0], a[1]);
            int y = max(a[0], a[1]);
            m[x*10+y]++;
        }
        int res = 0;
        for (unordered_map<int, int>::iterator it = m.begin();it!=m.end();it++) {
            res += it->second*(it->second-1)/2;
        }
        return res;
    }
};