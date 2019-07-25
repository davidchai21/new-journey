class Solution {
public:
    string removeVowels(string S) {
        string res = "";
        for (char a:S) {
            if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u') continue;
            res+=a;
        }
        return res;
    }
};