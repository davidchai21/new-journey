class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string word:words) {
            if (isValid(word, pattern)) res.push_back(word);
        }
        return res;
    }
    
    bool isValid(string word, string pattern) {
        vector<int> forward(26,-1);
        vector<int> backward(26,-1);
        for (int i=0;i<word.size();i++) {
            if (forward[word[i]-'a']!=-1 && forward[word[i]-'a']!=pattern[i] || backward[pattern[i]-'a']!=-1 && backward[pattern[i]-'a']!=word[i]) return false;
            forward[word[i]-'a']=pattern[i];
            backward[pattern[i]-'a']=word[i];
        }
        return true;
    }
};