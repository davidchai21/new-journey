class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty() || board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        if (!n) return false;
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (helper(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char> >& board, vector<vector<bool> >& visited, int i, int j, string word, int index) {
        if (index>=word.size()) return true;
        if (i<0 || j<0 || i>= board.size() || j>=board[0].size() || word[index]!=board[i][j] || visited[i][j]) return false;
        if (index == word.size()-1) return true;
        visited[i][j]=true;
        bool res = false;
        if (helper(board, visited, i+1,j,word,index+1) || helper(board, visited, i-1,j,word,index+1) || helper(board, visited, i,j+1,word,index+1) || helper(board, visited, i,j-1,word,index+1)) res = true;
        visited[i][j]=false;
        return res;
    }
};