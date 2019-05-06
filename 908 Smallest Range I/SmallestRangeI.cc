class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int imax = A[0];
        int imin = A[0];
        for (int i=1;i<A.size();i++) {
            if (imax < A[i]) imax = A[i];
            if (imin > A[i]) imin = A[i];
        }
        int res = imax-imin-2*K;
        return res<=0?0:res;
    }
};