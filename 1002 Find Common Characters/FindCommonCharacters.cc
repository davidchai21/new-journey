class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, INT_MAX);
        for (string a:A) {
            vector<int> word(26, 0);
            for (char c:a) {
                word[c-'a']++;
            }
            for (int i=0;i<26;i++) {
                count[i]=min(count[i], word[i]);
            }
        }
        vector<string> res;
        for (int i=0;i<26;i++) {
            if (count[i]) {
                while (count[i]--) {
                    string s = "";
                    s+='a'+i;
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};