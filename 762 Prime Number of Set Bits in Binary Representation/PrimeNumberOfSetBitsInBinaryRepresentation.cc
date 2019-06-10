class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i=L;i<=R;i++) {
            if (check(countPrime(i))) res++;
        }
        return res;
    }
    
    bool check(int n) {
        if (n<=1) return false;
        for (int i=2;i<=n/i;i++) {
            if (n%i==0) return false;
        }
        return true;
    }
    
    int countPrime(int n) {
        int res = 0;
        while (n) {
            res++;
            n&=n-1;
        }
        return res;
    }
};