class Solution {
public:
    int arrangeCoins(int n) {
        if (n<2) return n;
        long k = sqrt(2*(long)n);
        while (k*(k+1)/2>n) k--;
        return k;
    }
};