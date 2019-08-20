class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int> > q;
        int n = grid.size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) q.push(make_pair(i,j));
            }
        }
        if (q.empty() || q.size() == n*n) return -1;
        int step = 2;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k=0;k<4;k++) {
                    int _x = x+dir[k];
                    int _y = y+dir[k+1];
                    if (_x>=0 && _y>=0 && _x<n && _y<n) {
                        if (grid[_x][_y]==0 || grid[_x][_y]!=1 && grid[_x][_y]>step) {
                            grid[_x][_y]=step;
                            q.push(make_pair(_x,_y));
                        }
                    }
                }
            }
            step++;
        }
        return step-3;
    }
private:
    vector<int> dir = {0,1,0,-1,0};
};