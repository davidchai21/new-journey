class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        vector<int> table(26);
        iota(table.begin(), table.end(), 0);
        for (int i=0;i<A.size();i++) {
            Union(A[i]-'a', B[i]-'a', table);
        }
        string res(S.size(),'a');
        for (int i=0;i<S.size();i++) {
            res[i] = 'a'+Find(S[i]-'a', table);
        }
        return res;
    }
private:
    int Find(int val, vector<int>& table) {
        if (table[val]==val) return val;
        table[val] = Find(table[val], table);
        return table[val];
    }
    bool Union(int a, int b, vector<int>& table) {
        int pa = Find(a, table);
        int pb = Find(b, table);
        if (pa == pb) return false;
        int maxC = max(pa, pb);
        int minC = min(pa, pb);
        table[maxC] = minC;
        return true;
    }
};