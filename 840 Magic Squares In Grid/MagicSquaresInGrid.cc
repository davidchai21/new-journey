class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size()<3 || grid[0].size()<3) return 0;
        int res = 0;
        for (int i=1;i<grid.size()-1;i++) {
            for (int j=1;j<grid[0].size()-1;j++) {
                if (isValidNum(grid,i,j) && isMagic(grid, i,j)) res++;
            }
        }
        return res;
    }
    
    bool isMagic(vector<vector<int> >& grid, int x, int y) {
        int sum = grid[x-1][y-1]+grid[x-1][y]+grid[x-1][y+1];
        if (grid[x-1][y-1]+grid[x][y-1]+grid[x+1][y-1]==sum &&
           grid[x-1][y]+grid[x][y]+grid[x+1][y]==sum  &&
           grid[x-1][y+1]+grid[x][y+1]+grid[x+1][y+1]==sum &&
           grid[x][y-1]+grid[x][y]+grid[x][y+1]==sum &&
           grid[x+1][y-1]+grid[x+1][y]+grid[x+1][y+1]==sum &&
           grid[x-1][y-1]+grid[x][y]+grid[x+1][y+1]==sum &&
           grid[x-1][y+1]+grid[x][y]+grid[x+1][y-1]==sum) return true;
        return false;
    }
    
    bool isValidNum(vector<vector<int> >& grid, int x, int y) {
        if (grid[x][y]!=5) return false;
        vector<int> record(9,0);
        for (int i=-1;i<2;i++) {
            for (int j=-1;j<2;j++) {
                if (grid[x+i][y+j]>9 || grid[x+i][y+j]<1) return false;
                record[grid[x+i][y+j]-1]++;
                if (record[grid[x+i][y+j]-1]>1) return false;
            }
        }
        return true;
    }
};