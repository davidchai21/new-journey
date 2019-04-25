class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int odd = 0;
        int even = A.size()-1;
        while (odd < even) {
            while (odd < even && A[odd]%2 == 0) odd++;
            while (odd < even && A[even]%2) even--;
            if (odd < even) {
                int t = A[odd];
                A[odd++] = A[even];
                A[even--] = t;
            }
        }
        return A;
    }
};