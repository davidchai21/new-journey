class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long base = 5;
        while (n>=base) {
            res += n/base;
            base *= 5;
        }
        return res;
    }
};