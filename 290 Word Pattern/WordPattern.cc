class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_map<string, char> s;
        istringstream iss(str);
        string word;
        int i=0;
        while (iss>>word) {
            if (i>=pattern.size()) return false;
            if (m.find(pattern[i])!=m.end() && m[pattern[i]]!=word) return false;
            else m[pattern[i]] = word;
            if (s.find(word)!=s.end() && s[word]!=pattern[i]) return false;
            else s[word] = pattern[i];
            i++;
        }
        return i==pattern.size();
    }
};