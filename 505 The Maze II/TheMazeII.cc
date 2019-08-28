class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (m==0) return -1;
        int n = maze[0].size();
        if (n==0) return -1;
        
        int res = -1;
        vector<vector<int> > dist(m, vector<int>(n,-1));
        dist[start[0]][start[1]] = 0;
        queue<pair<int,int> > q;
        q.push(make_pair(start[0], start[1]));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i=0;i<4;i++) {
                int step=0;
                int _x = x+dir[i].first;
                int _y = y+dir[i].second;
                while (_x>=0 && _y>=0 && _x<m && _y<n && maze[_x][_y]!=1) {
                    step++;
                    _x+=dir[i].first;
                    _y+=dir[i].second;
                }
                _x-=dir[i].first;
                _y-=dir[i].second;
                if (dist[_x][_y]==-1 || dist[x][y]+step<dist[_x][_y]) {
                    dist[_x][_y]=step+dist[x][y];
                    q.push(make_pair(_x, _y));
                    if (_x == destination[0] && _y==destination[1]) res = res==-1?dist[_x][_y]:min(res, dist[_x][_y]);
                }
            }
        }
        return res;
    }
private:
    vector<pair<int,int> > dir = {{0,1},{0,-1},{-1,0},{1,0}};
};