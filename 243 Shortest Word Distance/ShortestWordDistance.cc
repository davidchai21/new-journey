class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int> > m;
        for (int i=0;i<words.size();i++) {
            m[words[i]].push_back(i);
        }
        int i=0;
        int j=0;
        int res = INT_MAX;
        while (i<m[word1].size() && j<m[word2].size()) {
            res = min(res, abs(m[word1][i]-m[word2][j]));
            if (m[word1][i]<m[word2][j]) i++;
            else j++;
        }
        return res;
    }
};