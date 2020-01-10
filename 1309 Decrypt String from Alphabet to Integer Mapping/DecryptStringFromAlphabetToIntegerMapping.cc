class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        int i=0;
        for (;i<s.size()-2;++i) {
            if (s[i+2]!='#') res+='a'+s[i]-'1';
            else {
                res+='a'+10*(s[i]-'0')+s[i+1]-'1';
                i+=2;
            }
        }
        while (i<s.size()) {
            res+='a'+s[i++]-'1';
        }
        return res;
    }
};