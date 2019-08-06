class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int index = 0;
        int res = 0;
        while (index < s.size()) {
            while (index<s.size() && s[index]==' ') index++;
            if (index>=s.size()) break;
            res++;
            while (index<s.size() && s[index]!=' ') index++;
        }
        return res;
    }
};