class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > res;
        int i=0;
        int j=0;
        while (i<A.size() && j<B.size()) {
            if (A[i][0]>B[j][1]) j++;
            else if (A[i][1]<B[j][0]) i++;
            else {
                vector<int> t = {max(A[i][0], B[j][0]), min(A[i][1], B[j][1])};
                res.push_back(t);
                if (A[i][1]>B[j][1]) j++;
                else i++;
            }
        }
        return res;
    }
};