class Solution {
public:
    string reverseVowels(string s) {
        if (s.size()<2) return s;
        int i=0;
        int j=s.size()-1;
        while (i<j) {
            while (i<s.size() && !isVowel(tolower(s[i]))) i++;
            while (j>=0 && !isVowel(tolower(s[j]))) j--;
            if (i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
    
    bool isVowel(char a) {
        if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return true;
        return false;
    }
};