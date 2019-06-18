class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> res(2,1);
        for (int i=1;i<rowIndex;i++) {
            int record = res[0];
            for (int j=1;j<res.size();j++) {
                int cur = res[j]+record;
                record = res[j];
                res[j]=cur;
            }
            res.push_back(1);
        }
        return res;
    }
};