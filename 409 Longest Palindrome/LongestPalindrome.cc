class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> record(256,0);
        for (char a:s) record[a]++;
        bool flag = false;
        int res = 0;
        for (int n:record) {
            res += n/2;
            if (n%2) flag=true;
        }
        return flag?2*res+1:2*res;
    }
};