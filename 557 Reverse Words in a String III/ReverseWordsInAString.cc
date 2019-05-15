class Solution {
public:
    string reverseWords(string s) {
        for (int i=0;i<s.size();) {
            int last=i;
            while(last<s.size() && s[last]!=' ') last++;
            int j=last-1;
            while (i<j) {
                swap(s[i++], s[j--]);
            }
            i=last+1;
        }
        return s;
    }
};