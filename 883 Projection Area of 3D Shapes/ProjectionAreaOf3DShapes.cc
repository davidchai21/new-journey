class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int max_c = 0;
        for (int i=0;i<grid.size();i++) {
            int imax = 0;
            for (int j=0;j<grid[i].size();j++) {
                imax = max(imax, grid[i][j]);
                if (grid[i][j]) res++;
            }
            res += imax;
            max_c = max(max_c, (int)grid[i].size());
        }
        for (int i=0;i<max_c;i++) {
            int jmax = 0;
            for (int j=0;j<grid.size();j++) {
                if (i<grid[j].size()) jmax = max(jmax, grid[j][i]);
            }
            res += jmax;
        }
        return res;
    }
};