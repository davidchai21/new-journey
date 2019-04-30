class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int k=0;k<A.size();k++) {
            int i=0;
            int j=A[k].size()-1;
            while (i<=j) {
                int t=A[k][i];
                A[k][i++]=1-A[k][j];
                A[k][j--]=1-t;
            }
        }
        return A;
    }
};