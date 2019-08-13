class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int> > q;
        int remain = 0;
        int res = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==2) q.push(make_pair(i,j));
                else if (grid[i][j]==1) remain++;
            }
        }
        if (!remain) return 0;
        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int i=0;i<size;i++) {
                pair<int,int> cur = q.front();
                q.pop();
                for (int j=0;j<4;j++) {
                    int x=cur.first+dir[j].first;
                    int y=cur.second+dir[j].second;
                    if (isValid(x,y,m,n) && grid[x][y]==1) {
                        grid[x][y]=2;
                        q.push(make_pair(x,y));
                        remain--;
                    }
                }
            }
        }
        return remain?-1:res-1;
    }
    
    bool isValid(int x, int y, int m, int n) {
        if (x>=0 && y>=0 && x<m && y<n) return true;
        return false;
    }
private:
    vector<pair<int,int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
};