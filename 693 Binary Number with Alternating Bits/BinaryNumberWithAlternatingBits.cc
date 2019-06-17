class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = -1;
        while (n) {
            int digit = n%2;
            if (bit == -1) bit = digit;
            else {
                if (bit == digit) return false;
                bit = digit;
            }
            n>>=1;
        }
        return true;
    }
};