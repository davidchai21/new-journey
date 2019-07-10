class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        if (word[0]==toupper(word[0])) {
            if (word[1]==toupper(word[1])) {
                for (int i=2;i<word.size();i++) {
                    if (word[i]<'A' || word[i]>'Z') return false;
                }
            } else {
                for (int i=2;i<word.size();i++) {
                    if (word[i]<'a' || word[i]>'z') return false;
                }
            }
        } else {
            for (int i=1;i<word.size();i++) {
                if (word[i]>='a' && word[i]<='z') continue;
                else return false;
            }
        }
        return true;
    }
};