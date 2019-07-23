class Solution {
public:
    bool confusingNumber(int N) {
        if (N<2) return false;
        int res = 0;
        int original = N;
        while (N) {
            int d = N%10;
            N/=10;
            switch (d) {
                case 0: res = res*10; break;
                case 1: res = res*10+1; break;
                case 6: res = res*10+9; break;
                case 8: res = res*10+8; break;
                case 9: res = res*10+6; break;
                default: return false;
            }
        }
        return res != original;
    }
};