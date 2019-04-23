class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, unordered_set<int> > m;
        for (int i=0;i<B.size();i++) {
            m[B[i]].insert(i);
        }
        vector<int> res(A.size(), -1);
        for (int i=0;i<A.size();i++) {
            res[i] = *(m[A[i]].begin());
            m[A[i]].erase(m[A[i]].begin());
        }
        return res;
    }
};