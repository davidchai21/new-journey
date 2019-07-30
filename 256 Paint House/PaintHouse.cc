class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<int> res = costs[0];
        for (int i=1;i<costs.size();i++) {
            vector<int> t = costs[i];
            t[0] += min(res[1],res[2]);
            t[1] += min(res[0],res[2]);
            t[2] += min(res[1],res[0]);
            res = t;
        }
        return min(res[0], min(res[1], res[2]));
    }
};