class Solution {
public:
    string toLowerCase(string str) {
        string res = "";
        for (char a:str) {
            if (a>='A' && a<='Z') res += a-'A'+'a';
            else res += a;
        }
        return res;
    }
};