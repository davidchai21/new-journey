class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for (string str:strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        vector<vector<string> > res;
        for (unordered_map<string, vector<string> >::iterator it = m.begin();it!=m.end();it++) {
            res.push_back(it->second);
        }
        return res;
    }
};