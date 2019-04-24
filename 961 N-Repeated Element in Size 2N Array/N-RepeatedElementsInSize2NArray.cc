class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int base = A[0];
        for (int i=0;i<A.size()/2;i++) {
            if (A[2*i] == A[2*i+1]) return A[2*i];
        }
        if (A[0] == A.back() || A[0] == A[A.size()-2]) return A[0];
        return A[1];
    }
};