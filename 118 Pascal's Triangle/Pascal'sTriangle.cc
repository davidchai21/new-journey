class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return {};
        vector<vector<int> > res;
        res.push_back({1});
        if (numRows==1) return res;
        res.push_back({1,1});
        if (numRows==2) return res;
        for (int i=3;i<=numRows;i++) {
            int pre = 1;
            vector<int> t = res[i-2];
            for (int j=1;j<t.size();j++) {
                int newVal = t[j]+pre;
                pre = t[j];
                t[j]=newVal;
            }
            t.push_back(1);
            res.push_back(t);
        }
        return res;
    }
};