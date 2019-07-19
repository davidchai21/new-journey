class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), [](int a, int b){return abs(a)>abs(b);});
        int res = 0;
        int i=0;
        while (i<A.size() && K) {
            if (A[i]<0) K--;
            res += abs(A[i++]);
        }
        if (K) {
            if (K%2) res -= 2*abs(A.back());
        } else {
            while (i<A.size()) res+=A[i++];
        }
        return res;
    }
};