class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > res;
        if (S.size()<3) return res;
        int index = 1;
        int length = 1;
        while (index < S.size()) {
            while (index<S.size() && S[index]==S[index-1]) {
                index++;
                length++;
            }
            if (length>=3) {
                res.push_back({index-length, index-1});
            }
            length = 1;
            index++;
        }
        return res;
    }
};