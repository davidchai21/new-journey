class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len = gcd(str1.size(), str2.size());
        for (int i=0;i<len;i++) {
            if (str1[i]!=str2[i]) return "";
        }
        return str1.substr(0,len);
    }
    
    int gcd(int a, int b) {
        int x = max(a,b);
        int y = min(a,b);
        while (x%y) {
            int t = x%y;
            x = y;
            y = t;
        }
        return y;
    }
};