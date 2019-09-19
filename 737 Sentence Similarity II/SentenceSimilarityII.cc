class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        for (vector<string>& p:pairs) {
            Union(p[0], p[1]);
        }
        for (int i=0;i<words1.size();i++) {
            if (words1[i]==words2[i]) continue;
            string pa = Find(words1[i]);
            string pb = Find(words2[i]);
            if (pa != pb) return false;
        }
        return true;
    }
private:
    unordered_map<string, string> m;
    string Find(string a) {
        if (m.find(a)==m.end()) {
            m[a]=a;
        }
        if (m[a]==a) return a;
        m[a] = Find(m[a]);
        return m[a];
    }
    bool Union(string& a, string& b) {
        string pa = Find(a);
        string pb = Find(b);
        if (pa == pb) return false;
        m[pa]=pb;
        return true;
    }
};