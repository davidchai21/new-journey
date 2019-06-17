class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(256,0);
        for (char a:s) count[a]++;
        for (char a:t) count[a]--;
        for (int i=0;i<256;i++) {
            if (count[i]) return false;
        }
        return true;
    }
};