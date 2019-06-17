class Solution {
public:
    string toGoatLatin(string S) {
        string res = "";
        int countA = 1;
        int i = 0;
        while(i<S.size()) {
            while (i<S.size() && S[i]==' ') i++;
            if (i<S.size()) {
                int j=i+1;
                while (j<S.size() && S[j]!=' ') j++;
                res+=(res==""?"":" ")+getGoat(S.substr(i, j-i), countA++);
                i=j+1;
            }
        }
        return res;
    }
    
    string getGoat(string s, int num) {
        if (dic.find(s[0])!=dic.end()) return s+"ma"+string(num, 'a');
        return s.substr(1)+s[0]+"ma"+string(num, 'a');
    }
private:
    unordered_set<char> dic = {'a','A','e','E','i','I','o','O','u','U'};
};