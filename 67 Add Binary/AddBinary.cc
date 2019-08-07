class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i=a.size()-1;
        int j=b.size()-1;
        int digit = 0;
        while (i>=0 || j>=0 || digit) {
            if (i>=0) digit += a[i--]-'0';
            if (j>=0) digit += b[j--]-'0';
            res = (char)(digit%2+'0') + res;
            digit /=2;
        }
        return res;
    }
};