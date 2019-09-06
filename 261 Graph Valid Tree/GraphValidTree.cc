class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int size = edges.size();
        if (size != n-1) return false;
        vector<int> dic(n);
        for (int i=0;i<n;i++) dic[i]=i;
        for (vector<int>& edge : edges) {
            if (!Union(dic, edge[0], edge[1])) return false;
        }
        return true;
    }
    
    bool Union(vector<int>& dic, int a, int b) {
        int pa = Find(dic, a);
        int pb = Find(dic, b);
        if (pa == pb) return false;
        dic[pa] = pb;
        return true;
    }
    
    int Find(vector<int>& dic, int n) {
        int pn = dic[n];
        while (pn != dic[pn]) {
            pn = dic[pn];
        }
        return pn;
    }
};