class Solution {
public:
    int bitwiseComplement(int N) {
        if (N==0) return 1;
        int res = 0;
        int base = 1;
        while (N) {
            if (N%2==0) res+=base;
            base*=2;
            N>>=1;
        }
        return res;
    }
};