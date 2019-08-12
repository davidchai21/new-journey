class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index = 0;
        int count = 0;
        for (int i=0;i<abbr.size();i++) {
            if (isdigit(abbr[i])) {
                if (count==0 && abbr[i]=='0') return false;
                count = count*10 + abbr[i]-'0';
                if (i==abbr.size()-1 || isalpha(abbr[i+1])) {
                    index += count;
                    count = 0;
                }
            } else {
                if (index>=word.size() || abbr[i]!=word[index++]) return false;
            }
        }
        return index == word.size();
    }
};