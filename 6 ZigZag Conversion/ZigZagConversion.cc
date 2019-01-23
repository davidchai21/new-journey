class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string res = "";
        for (int i=0; i<numRows; i++) {
            int j = 0;
            string t = "";
            while (i+j<s.size()) {
                t+=s[j+i];
                if (i!=0 && i!=numRows-1 && (j+i+2*(numRows-i-1)<s.size())) t+=s[j+i+2*(numRows-i-1)];
                j+=2*(numRows-1);
            }
            res+=t;
        }
        return res;
    }
};