class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n,0);
        vector<int> col(m,0);
        for (vector<int> index:indices) {
            row[index[0]] = 1-row[index[0]];
            col[index[1]] = 1-col[index[1]];
        }
        int res = 0;
        int odd = 0;
        for (int r:row) {
            if (r) {
                ++odd;
                res+=m;
            }
        }
        for (int c:col) {
            if (c) {
                res+= n-2*odd;
            }
        }
        return res;
    }
};