class Solution {
public:
    string reverseStr(string s, int k) {
        if (k==1) return s;
        int i=0;
        for (;i+k<=s.size();i+=2*k) {
            for (int j=i;j<i+k/2;j++) {
                swap(s[j], s[2*i+k-j-1]);
            }
        }
        reverse(s.begin()+i, s.end());
        return s;
    }
};