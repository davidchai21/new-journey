class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int> > res;
        if (words.empty()) return res;
        for (string word:words) {
            size_t pos = text.find(word);
            while (pos!=string::npos) {
                res.push_back({pos, pos+word.size()-1});
                pos = text.find(word, pos+1);
            }
        }
        sort(res.begin(), res.end(), [](vector<int> a, vector<int> b){return a[0]<b[0] || a[0]==b[0] && a[1]<b[1];});
        return res;
    }
};