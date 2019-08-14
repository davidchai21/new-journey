class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board = vector<vector<int> >(n, vector<int>(n,0));
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col]=player;
        if (check(board,n,row,col,player)) return player;
        return 0;
    }
private:
    vector<vector<int> > board;
    int n=0;
    bool check(vector<vector<int> >& board, int n, int x, int y, int player) {
        int sum = 0;
        for (int i=0;i<n;i++) {
            if (board[x][i]!=player) break;
            else sum++;
        }
        if (sum == n) return true;
        sum=0;
        for (int i=0;i<n;i++) {
            if (board[i][y]!=player) break;
            else sum++;
        }
        if (sum == n) return true;
        if (x+y+1==n) {
            sum=0;
            for (int i=0;i<n;i++) {
                if (board[i][n-1-i]!=player) break;
                else sum++;
            }
            if (sum==n) return true;
        }
        if (x==y) {
            sum = 0;
            for (int i=0;i<n;i++) {
                if (board[i][i]!=player) break;
                else sum++;
            }
            if (sum==n) return true;
        }
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */