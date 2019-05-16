class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> m;
        vector<string> res;
        getWord(A,m);
        getWord(B,m);
        for (auto a=m.begin();a!=m.end();a++) {
            if (a->second == 1) res.push_back(a->first);
        }
        return res;
    }
    
    void getWord(string s, unordered_map<string, int>& m) {
        int i=0;
        while (i<s.size()) {
            while (s[i]==' ') i++;
            int j=i+1;
            while (j<s.size() && s[j]!=' ') j++;
            m[s.substr(i,j-i)]++;
            i = j;
        }
    }
};