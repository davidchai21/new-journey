class Solution {
public:
    int climbStairs(int n) {
        if (n<=1) return 1;
        int lower = 1;
        int upper = 2;
        for (int i=2;i<n;i++) {
            int total = lower+upper;
            lower = upper;
            upper = total;
        }
        return upper;
    }
};