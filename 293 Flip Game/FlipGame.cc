class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.empty()) return res;
        for (int i=0;i<s.size()-1;i++) {
            if (s[i]=='+' && s[i]==s[i+1] ) {
                    res.push_back(s.substr(0,i)+"--"+s.substr(i+2));
            }
        }
        return res;
    }
};