class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        if (n<1) return res;
        while (n) {
            char d = (n-1)%26+'A';
            res = d+res;
            n=(n-1)/26;
        }
        return res;
    }
};