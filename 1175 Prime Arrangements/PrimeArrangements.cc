class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n<3) return 1;
        int k=getPrime(n);
        long res = 1;
        for (int i=2;i<=k;i++) {
            res*=i;
            res%=base;
        }
        for (int i=2;i<=n-k;i++) {
            res*=i;
            res%=base;
        }
        return res;
    }
    
    int getPrime(int n) {
        vector<bool> res(n+1,true);
        res[0]=res[1]=false;
        for (int i=2;i<=n;i++) {
            if (res[i]) {
                for (int j=2*i;j<=n;j+=i) res[j]=false;
            }
        }
        int count = 0;
        for (int i=2;i<=n;i++) {
            if (res[i]) count++;
        }
        return count;
    }
private:
    const int base = 1000000007;
};