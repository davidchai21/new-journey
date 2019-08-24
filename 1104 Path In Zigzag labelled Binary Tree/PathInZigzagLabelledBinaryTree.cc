class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int val = label;
        while (val) {
            res.push_back(val);
            val/=2;
        }
        reverse(res.begin(), res.end());
        for (int i=res.size()-2;i>=1;i-=2) {
            int base = pow(2,i);
            res[i] = 3*base-1-res[i];
        }
        return res;
    }
};