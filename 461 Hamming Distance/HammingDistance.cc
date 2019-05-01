class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int mixed = x^y;
        while (mixed) {
            res++;
            mixed &= mixed-1;
        }
        return res;
    }
};