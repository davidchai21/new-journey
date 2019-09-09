class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> record(N);
        iota(record.begin(), record.end(), 0);
        int count = N;
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        for (vector<int>& log:logs) {
            if (Union(log[1], log[2], record)) count--;
            if (count==1) return log[0];
        }
        return -1;
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
        record[pa]=pb;
        return true;
    }
};