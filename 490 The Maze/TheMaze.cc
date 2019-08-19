// BFS:
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int> > q;
        q.push(make_pair(start[0], start[1]));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            while (x-1>=0 && maze[x-1][y]!=1) x--;
            if (maze[x][y]!=-1) {
                if (x==destination[0] && y==destination[1]) return true;
                maze[x][y]=-1;
                q.push(make_pair(x,y));
            }
            x = q.front().first;
            while (x+1<m && maze[x+1][y]!=1) x++;
            if (maze[x][y]!=-1) {
                if (x==destination[0] && y==destination[1]) return true;
                maze[x][y]=-1;
                q.push(make_pair(x,y));
            }
            x = q.front().first;
            while (y-1>=0 && maze[x][y-1]!=1) y--;
            if (maze[x][y]!=-1) {
                if (x==destination[0] && y==destination[1]) return true;
                maze[x][y]=-1;
                q.push(make_pair(x,y));
            }
            y = q.front().second;
            while (y+1<n && maze[x][y+1]!=1) y++;
            if (maze[x][y]!=-1) {
                if (x==destination[0] && y==destination[1]) return true;
                maze[x][y]=-1;
                q.push(make_pair(x,y));
            }
            q.pop();
        }
        return false;
    }
};

// DFS:
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return helper(maze, start[0], start[1], destination);
    }
    
    bool helper(vector<vector<int> >& maze, int m, int n, vector<int>& destination) {
        maze[m][n]=-1;
        int x,y;
        bool res = false;
        for (int i=0;i<4;i++) {
            x=m;
            y=n;
            while (x+dir[i].first>=0 && x+dir[i].first<maze.size() && y+dir[i].second>=0 && y+dir[i].second<maze[0].size() && maze[x+dir[i].first][y+dir[i].second]!=1) {
                x+=dir[i].first;
                y+=dir[i].second;
            }
            if (x==destination[0] && y == destination[1]) return true;
            if (maze[x][y]!=-1) res |= helper(maze, x, y, destination);
            if (res) return true;
        }
        return res;
    }
private:
    vector<pair<int,int> > dir = {{0,1},{0,-1},{1,0},{-1,0}};
};