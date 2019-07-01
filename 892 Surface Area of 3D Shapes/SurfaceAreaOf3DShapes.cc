class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int N=grid.size();
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (grid[i][j]) res+=2;
                if (i==0) res+=grid[i][j];
                else res+= max(0,grid[i][j]-grid[i-1][j]);
                if (i==N-1) res+=grid[i][j];
                else res+= max(0,grid[i][j]-grid[i+1][j]);
                if (j==0) res+=grid[i][j];
                else res+= max(0,grid[i][j]-grid[i][j-1]);
                if (j==N-1) res+=grid[i][j];
                else res+= max(0,grid[i][j]-grid[i][j+1]);
            }
        }
        return res;
    }
};