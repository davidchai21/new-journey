class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s;
        for (string a:banned) s.insert(a);
        unordered_map<string, int> m;
        int len = 0;
        string word = "";
        string res = "";
        for (int i=0;i<paragraph.size();i++) {
            if (!isalpha(paragraph[i])) {
                if (!word.empty()) {
                    m[word]++;
                    if (m[word]>len && s.find(word)==s.end()) {
                        len = m[word];
                        res = word;
                    }
                    word = "";
                }
            } else {
                word+=tolower(paragraph[i]);
            }
        }
        if (!word.empty()) {
            m[word]++;
            if (m[word]>len) res = word;
        }
        return res;
    }
};