class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;
        for (int i=0;i<m;i++) {
            if (board[i][0]=='O') stayUntouched(board, i, 0);
            if (board[i].back()=='O') stayUntouched(board, i, n-1);
        }
        for (int i=0;i<n;i++) {
            if (board[0][i]=='O') stayUntouched(board, 0, i);
            if (board[m-1][i]=='O') stayUntouched(board, m-1, i);
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='B') board[i][j]='O';
            }
        }
    }
    
    void stayUntouched(vector<vector<char> >& board, int x, int y) {
        cout<<x<<"::"<<y<<endl;
        queue<pair<int,int> > q;
        q.push(make_pair(x,y));
        board[x][y]='B';
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                int _x = i+dir[k];
                int _y = j+dir[k+1];
                if (_x>=0 && _x<board.size() && _y>=0 && _y<board[0].size() && board[_x][_y]=='O') {
                    q.push(make_pair(_x,_y));
                    board[_x][_y]='B';
                }
            }
        }
    }
private:
    vector<int> dir = {1,0,-1,0,1};
};