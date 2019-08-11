class Solution {
public:
    int numWays(int n, int k) {
        if (k==0 || n==0) return 0;
        if (n<3) return pow(k,n);
        int first = k;
        int second = k*(k-1);
        for (int i=2;i<n;i++) {
            int t = (k-1)*(first+second);
            first = second;
            second = t;
        }
        return first + second;
    }
};