class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> recordx, recordy, res;
        if (bound<2) return res;
        unordered_set<int> s;
        if (x!=1) {
            for (int i=1; i<=bound;i*=x) recordx.push_back(i);
        } else recordx.push_back(1);
        if (y!=1) {
            for (int i=1; i<=bound;i*=y) recordy.push_back(i);
        } else recordy.push_back(1);
        for (int i=0;i<recordx.size();i++) {
            for (int j=0;j<recordy.size();j++) {
                int t = recordx[i]+recordy[j];
                if (t<=bound && s.find(t)==s.end()) {
                    res.push_back(t);
                    s.insert(t);
                }
            }
        }
        return res;
    }
};