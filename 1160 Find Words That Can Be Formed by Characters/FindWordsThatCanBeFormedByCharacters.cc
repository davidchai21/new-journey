class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        if (words.empty() || chars.empty()) return res;
        vector<int> dic(26,0);
        for (char c:chars) dic[c-'a']++;
        for (int i=0;i<words.size();i++) {
            vector<int> a(26,0);
            for (int j=0;j<words[i].size();j++) a[words[i][j]-'a']++;
            if (compareWords(a,dic)) res+=words[i].size();
        }
        return res;
    }
    
    bool compareWords(vector<int> a, vector<int> dic) {
        for (int i=0;i<26;i++) {
            if (a[i]>dic[i]) return false;
        }
        return true;
    }
};