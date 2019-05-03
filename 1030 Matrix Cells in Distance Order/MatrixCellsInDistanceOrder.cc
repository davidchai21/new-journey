class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        unordered_map<int, vector<vector<int> > > m;
        int maxLength = 0;
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                int dis = getDistance(r0,c0,i,j);
                m[dis].push_back({i,j});
                maxLength = max(maxLength, dis);
            }
        }
        vector<vector<int> > res;
        for (int i=0;i<=maxLength;i++) {
            for (int j=0;j<m[i].size();j++) {
                res.push_back(m[i][j]);
            }
        }
        return res;
    }
    
    int getDistance(int r0, int c0, int r, int c) {
        return abs(r-r0)+abs(c-c0);
    }
};