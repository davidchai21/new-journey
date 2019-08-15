// DFS:
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty()) return res;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]=='1') {
                    helper(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<char> >& grid, int x, int y) {
        if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]=='0') return;
        grid[x][y]='0';
        helper(grid,x-1,y);
        helper(grid,x+1,y);
        helper(grid,x,y-1);
        helper(grid,x,y+1);
    }
};

// BFS:
// Important: We have to change the value first to avoid TLE!!!
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty()) return res;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]=='1') {
                    res++;
                    queue<pair<int,int> > q;
                    q.push(make_pair(i,j));
                    grid[i][j]='0';
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (x-1>=0 && grid[x-1][y]=='1') {
                            grid[x-1][y]='0';
                            q.push(make_pair(x-1,y));
                        }
                        if (x+1<grid.size() && grid[x+1][y]=='1') {
                            q.push(make_pair(x+1,y));
                            grid[x+1][y]='0';
                        }
                        if (y-1>=0 && grid[x][y-1]=='1') {
                            q.push(make_pair(x,y-1));
                            grid[x][y-1]='0';
                        }
                        if (y+1<grid[0].size() && grid[x][y+1]=='1') {
                            q.push(make_pair(x,y+1));
                            grid[x][y+1]='0';
                        }
                    }
                }
            }
        }
        return res;
    }
};