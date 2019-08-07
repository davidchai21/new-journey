class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        unordered_set<string> s(words.begin(), words.end());
        vector<bool> record(S.size(), false);
        for (int i=0;i<S.size();i++) {
            for (int j=1;j+i<=S.size();j++) {
                string sub = S.substr(i,j);
                if (s.find(sub)!=s.end()) {
                    for (int k=i;k<i+j;k++) {
                        record[k]=true;
                    }
                }
            }
        }
        bool flag = false;
        string res = "";
        for (int i=0;i<S.size();i++) {
            if (record[i]) {
                if (flag == false) {
                    flag = true;
                    res += "<b>";
                }
            } else {
                if (flag == true) {
                    flag = false;
                    res+="</b>";
                }
            }
            res+=S[i];
        }
        if (flag) res+="</b>";
        return res;
    }
};