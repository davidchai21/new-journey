class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> record(n);
        for (int i=0;i<n;i++) record[i]=i;
        int res = n;
        for (vector<int>& edge: edges) {
            if (Union(edge[0], edge[1], record)) res--;
        }
        return res;
    }
private:
    int Find(int a, vector<int>& record) {
        while (a!=record[a]) {
            record[a] = record[record[a]];
            a = record[a];
        }
        return a;
    }
    
    bool Union(int a, int b, vector<int>& record) {
        int pa = Find(a, record);
        int pb = Find(b, record);
        if (pa != pb) {
            record[pa] = pb;
            return true;
        }
        return false;
    }
};

// Building a Class:
class UnionFind {
public:
    UnionFind(int n) {
        count = n;
        rank.resize(n,0);
        record.resize(n);
        for (int i=0;i<n;i++) record[i]=i;
    }
    
    int Find(int a) {
        if (a==record[a]) return a;
        record[a]=Find(record[a]);
        return record[a];
    }
    
    bool Union(int a, int b) {
        int pa = Find(a);
        int pb = Find(b);
        if (pa == pb) return false;
        if (rank[pa]>rank[pb]) {
            record[pb]=pa;
        } else if (rank[pb]>rank[pa]) {
            record[pa]=pb;
        } else {
            record[pa]=pb;
            rank[pb]++;
        }
        count--;
        return true;
    }
    
    int getCount() {
        return count;
    }
private:
    int count;
    vector<int> record, rank;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind* uf = new UnionFind(n);
        for (vector<int>& edge: edges) {
            (*uf).Union(edge[0], edge[1]);
        }
        return uf->getCount();
    }
};