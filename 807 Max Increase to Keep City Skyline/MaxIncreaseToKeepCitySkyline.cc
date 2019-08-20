class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> h(n);
        vector<int> v(n);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                h[i]=max(h[i], grid[i][j]);
                v[j]=max(v[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                res += min(h[i],v[j]) - grid[i][j];
            }
        }
        return res;
    }
};