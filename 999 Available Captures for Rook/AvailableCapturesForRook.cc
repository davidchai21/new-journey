class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = -1;
        int c = -1;
        int res = 0;
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                if (board[i][j]=='R') {
                    r = i;
                    c = j;
                    i = board.size();
                    j = board[0].size();
                }
            }
        }
        // up
        for (int i=r-1;i>=0;i--) {
            if (board[i][c]=='B') break;
            else if (board[i][c] =='p') {
                res++;
                break;
            }
        }
        // down
        for (int i=r+1;i<board.size();i++) {
            if (board[i][c]=='B') break;
            else if (board[i][c] =='p') {
                res++;
                break;
            }
        }
        // left
        for (int i=c-1;i>=0;i--) {
            if (board[r][i]=='B') break;
            else if (board[r][i]=='p') {
                res++;
                break;
            }
        }
        // right
        for (int i=c+1;i<board[0].size();i++) {
            if (board[r][i]=='B') break;
            else if (board[r][i]=='p') {
                res++;
                break;
            }
        }
        return res;
    }
};