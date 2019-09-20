class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> m;
        for (char a:S) {
            m[a]=0;
        }
        string residue = "";
        for (char a:T) {
            if (m.find(a)!=m.end()) {
                m[a]++;
            } else residue+=a;
        }
        string res = "";
        for (char a:S) {
            res += string(m[a], a);
        }
        res += residue;
        return res;
    }
};