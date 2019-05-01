class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.size()<2) return A;
        int odd = 1;
        int even = 0;
        while (odd < A.size()) {
            while (odd< A.size() && A[odd]%2) odd+=2;
            while (even < A.size() && A[even]%2==0) even+=2;
            if (odd<A.size()) {
                swap(A[odd], A[even]);
                odd +=2;
                even +=2;
            }
        }
        return A;
    }
};