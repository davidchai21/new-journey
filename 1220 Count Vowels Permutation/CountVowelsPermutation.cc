class Solution {
public:
    int countVowelPermutation(int n) {
        long a=1;
        long e=1;
        long i=1;
        long o=1;
        long u=1;
        for (int k=1;k<n;k++) {
            long _a = e+i+u;
            long _e = a+i;
            long _i = e+o;
            long _o = i;
            long _u = i+o;
            a = _a%M;
            e = _e%M;
            i = _i%M;
            o = _o%M;
            u = _u%M;
        }
        return (a+e+i+o+u)%M;
    }
private:
    const int M = 1000000007;
};