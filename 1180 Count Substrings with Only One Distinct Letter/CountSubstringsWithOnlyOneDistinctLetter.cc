class Solution {
public:
    int countLetters(string S) {
        int sum = 0;
        char a = S[0];
        int res = 0;
        for (char c:S) {
            if (c==a) {
                res += ++sum;
            } else {
                a = c;
                sum = 1;
                ++res;
            }
        }
        return res;
    }
};