class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int amin = arrays[0][0];
        int amax = arrays[0].back();
        int res = INT_MIN;
        for (int i=1;i<arrays.size();i++) {
            res = max(res, max(amax-arrays[i][0], arrays[i].back()-amin));
            amin = min(amin, arrays[i][0]);
            amax = max(amax, arrays[i].back());
        }
        return res;
    }
};