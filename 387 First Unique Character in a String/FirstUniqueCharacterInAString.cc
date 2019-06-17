class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(256,0);
        for (char a:s) {
            count[a]++;
        }
        for (int i=0;i<s.size();i++) {
            if (count[s[i]]==1) return i;
        }
        return -1;
    }
};