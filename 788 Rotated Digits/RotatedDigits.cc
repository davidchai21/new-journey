class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i=2;i<=N;i++) {
            if (check(i)) res++;
        }
        return res;
    }
    
    bool check(int n) {
        int reserved = n;
        int res = 0;
        int base = 1;
        while (n) {
            int d = n%10;
            switch (d) {
                case 0: break;
                case 1: res += base; break;
                case 2: res += base*5; break;
                case 5: res += base*2; break;
                case 6: res += base*9; break;
                case 8: res += base*8; break;
                case 9: res += base*6; break;
                default: return false;
            }
            base *= 10;
            n/=10;
        }
        return res!=reserved;
    }
};