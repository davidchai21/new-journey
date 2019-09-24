class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if (mat.size() ==1) return mat[0][0];
        int size = mat[0].size();
        vector<int> index(mat.size(),0);
        int i = 1;
        while (i<mat.size()) {
            if (mat[i][index[i]]==mat[0][index[0]]) {
                ++i;
                continue;
            }
            while (index[i]<size && mat[i][index[i]]<mat[0][index[0]]) ++index[i];
            if (index[i]==size) return -1;
            if (mat[i][index[i]]>mat[0][index[0]]) {
                ++index[0];
                if (index[0]==size) return -1;
                i=1;
            }
        }
        return mat[0][index[0]];
    }
};