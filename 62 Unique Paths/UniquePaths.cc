class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<2 || n<2) return min(m,n);
        vector<int> rec(n,1);
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                rec[j]+=rec[j-1];
            }
        }
        return rec.back();
    }
};