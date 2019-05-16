class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int bit = 0;
        while (num) {
            int digit = num&1;
            if (digit==0) res |= 1<<bit;
            bit++;
            num>>=1;
        }
        return res;
    }
};