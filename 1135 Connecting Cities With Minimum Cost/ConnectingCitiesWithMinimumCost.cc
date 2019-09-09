class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        record.resize(N);
        iota(record.begin(), record.end(), 0);
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b){return a[2]<b[2];});
        int count = N;
        int cost = 0;
        for (vector<int>& con: connections) {
            if (Union(con[0], con[1])) {
                N--;
                cost += con[2];
            }
            if (N==1) return cost;
        }
        return -1;
    }
private:
    vector<int> record;
    
    int Find(int a) {
        if (a==record[a]) return a;
        record[a]=Find(record[a]);
        return record[a];
    }
    
    bool Union(int a, int b) {
        int pa = Find(a-1);
        int pb = Find(b-1);
        if (pa == pb) return false;
        record[pa] = pb;
        return true;
    }
};