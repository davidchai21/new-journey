class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        if (m==0 || n==0) return res;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]) {
                    res = max(res, helper(grid,i,j));
                }
            }
        }
        return res;
    }
private:
    vector<int> dir = {0,1,0,-1,0};
    int helper(vector<vector<int> >& grid, int x, int y) {
        if (grid[x][y]==0) return 0;
        grid[x][y]=0;
        int res = 1;
        for (int i=0;i<4;++i) {
            int _x = x+dir[i];
            int _y = y+dir[i+1];
            if (_x>=0 && _y>=0 && _x<grid.size() && _y<grid[0].size()) res += helper(grid, _x, _y);
        }
        return res;
    }
};