class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A[0].size();
        vector<int> record = A[0];
        for (int i=1;i<A.size();++i) {
            vector<int> t(size);
            for (int j=0;j<size;++j) {
                int val = record[j];
                if (j-1>=0) val = min(val, record[j-1]);
                if (j+1<size) val = min(val, record[j+1]);
                t[j] = val+A[i][j];
            }
            record = t;
        }
        int res = record[0];
        for (int i=1;i<size;++i) {
            res = min(res, record[i]);
        }
        return res;
    }
};