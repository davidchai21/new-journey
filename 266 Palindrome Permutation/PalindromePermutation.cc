class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char c:s) {
            m[c]++;
        }
        bool flag = false;
        for (auto ite=m.begin();ite!=m.end();ite++) {
            if (ite->second%2) {
                if (!flag) flag = true;
                else return false;
            }
        }
        return true;
    }
};