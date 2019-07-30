class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int column = M[0].size();
        for (int i=0;i<row;i++) {
            for (int j=0;j<column; j++) {
                int sum = M[i][j]&0xff;
                int count = 1;
                for (int k=0;k<8;k++) {
                    if (isValid(i+dir[k][0], j+dir[k][1], row, column)) {
                        sum += M[i+dir[k][0]][j+dir[k][1]]&0xff;
                        count++;
                    }
                }
                M[i][j] |= (int)floor(sum/count)<<8;
            }
        }
        for (int i=0;i<row;i++) {
            for (int j=0;j<column;j++) {
                M[i][j] >>= 8;
            }
        }
        return M;
    }
    
private:
    vector<vector<int> > dir = {{0,1}, {0,-1}, {1,0}, {-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
    bool isValid(int x, int y, int row, int col) {
        if (x>=0 && x<row && y>=0 && y<col) return true;
        return false;
    }
};