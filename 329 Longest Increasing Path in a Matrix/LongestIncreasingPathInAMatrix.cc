class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res = 0;
        vector<vector<int> > record(m, vector<int>(n,0));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                res = max(res, helper(matrix, record, i, j));
            }
        }
        return res;
    }
    
    int helper(vector<vector<int> >& matrix, vector<vector<int> >& record, int x, int y) {
        if (record[x][y]) return record[x][y];
        for (int k=0;k<4;k++) {
            int _x = x+dir[k].first;
            int _y = y+dir[k].second;
            if (_x>=0 && _y>=0 && _x<matrix.size() && _y<matrix[0].size() && matrix[x][y]>matrix[_x][_y]) {
                record[x][y] = max(record[x][y], helper(matrix, record, _x, _y));
            }
        }
        return ++record[x][y];
    }
private:
    vector<pair<int,int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
};