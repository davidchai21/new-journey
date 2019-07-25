class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int> > res;
        unordered_map<int, vector<int> > m;
        for (vector<int> item:items) {
            m[item[0]].push_back(item[1]);
        }
        for (unordered_map<int, vector<int> >::iterator it=m.begin();it!=m.end();it++) {
            sort(it->second.begin(), it->second.end(), greater<int>());
            int sum = 0;
            for (int i=0;i<5;i++) sum += it->second[i];
            res.push_back({it->first, sum/5});
        }
        sort(res.begin(), res.end(), [](vector<int> a, vector<int> b){return a[0]<b[0];});
        return res;
    }
};