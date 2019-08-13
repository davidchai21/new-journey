class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        if (n==3) return 1;
        vector<bool> record(n+1,true);
        record[0]=false;
        record[1]=false;
        int res = 1;
        for (long i=3;i<n;i+=2) {
            if (record[i]) {
                res++;
                for (long j=i*i;j<n;j+=i) {
                    record[j]=false;
                }
            }
        }
        return res;
    }
};