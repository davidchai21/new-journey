class Solution {
public:
    bool checkRecord(string s) {
        int count = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='A') {
                if (count) return false;
                count++;
            } else if (s[i]=='L') {
                if (i+2<s.size() && s[i+1]=='L' && s[i+2]=='L') return false;
            }
        }
        return true;
    }
};