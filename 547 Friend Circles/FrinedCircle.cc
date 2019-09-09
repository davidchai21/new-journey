class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> record(n);
        iota(record.begin(), record.end(), 0);
        int res = n;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                if (M[i][j] && Union(i, j, record)) {
                    res--;
                }
            }
        }
        return res;
    }
private:
    int Find(int a, vector<int>& record) {
        if (a==record[a]) return a;
        record[a]=Find(record[a], record);
        return record[a];
    }
    
    bool Union(int a, int b, vector<int>& record) {
        int pa = Find(a, record);
        int pb = Find(b, record);
        if (pa == pb) return false;
        record[pa] = pb;
        return true;
    }
};