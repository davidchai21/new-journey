class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> s;
        string res = "";
        int length = 0;
        for (string word: words) {
            if (word.size()==1 || s.find(word.substr(0, word.size()-1))!=s.end()) {
                s.insert(word);
                if (word.size()>length) {
                    length = word.size();
                    res = word;
                }
            }
        }
        return res;
    }
};