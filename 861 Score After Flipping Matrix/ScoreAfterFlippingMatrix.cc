class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        for (int i=0;i<m;i++) {
            if (A[i][0]==0) toggle(A, i);
        }
        for (int col=1;col<n;col++) {
            int ones = 0;
            for (int i=0;i<m;i++) {
                if (A[i][col]==1) ones++;
            }
            if (2*ones<m) toggleCol(A, col);
        }
        int res = 0;
        for (int i=0;i<m;i++) {
            int base = 1;
            for (int j=n-1;j>=0;j--) {
                res+=base*A[i][j];
                base<<=1;
            }
        }
        return res;
    }
    
    void toggle(vector<vector<int> >& A, int row) {
        for (int i=0;i<A[0].size();i++) {
            A[row][i] = 1-A[row][i];
        }
    }
    
    void toggleCol(vector<vector<int> >& A, int col) {
        for (int i=0;i<A.size();i++) {
            A[i][col] = 1-A[i][col];
        }
    }
};