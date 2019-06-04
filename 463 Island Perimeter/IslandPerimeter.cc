class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int res = 0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]==1) res += getSide(grid, i, j);
            }
        }
        return res;
    }
    
    int getSide(vector<vector<int> >& grid, int x, int y) {
        int res = 0;
        if (y==0 || grid[x][y-1]==0) res++;
        if (x==0 || grid[x-1][y]==0) res++;
        if (y==grid[0].size()-1 || grid[x][y+1]==0) res++;
        if (x==grid.size()-1 || grid[x+1][y]==0) res++;
        return res;
    }
};