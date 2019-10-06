class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        int total = 0;
        int res = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                total += grid[i][j];
                if (grid[i][j]==0) {
                    res = max(res, helper(grid, i, j, visited));
                }
            }
        }
        return res == 0?total:res;
    }
private:
    vector<int> dir = {0,1,0,-1,0};
    int helper(vector<vector<int> >& grid, int x, int y, vector<vector<bool> >& visited) {
        int res = 0;
        for (int i=0;i<4;i++) {
            int _x = x+dir[i];
            int _y = y+dir[i+1];
            if (_x>=0 && _y>=0 && _x<grid.size() && _y<grid[0].size() && grid[_x][_y] && !visited[_x][_y]) {
                visited[_x][_y] = true;
                res = max(res, grid[_x][_y]+helper(grid, _x, _y, visited));
                visited[_x][_y] = false;
            }
        }
        return res;
    }
};