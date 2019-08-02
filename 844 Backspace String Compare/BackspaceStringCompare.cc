class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t;
        for (char a:S) {
            if (a=='#') {
                if (!s.empty()) s.pop();
            }
            else s.push(a);
        }
        for (char a:T) {
            if (a=='#') {
                if (!t.empty()) t.pop();
            }
            else t.push(a);
        }
        while (!s.empty() && !t.empty()) {
            if (s.top()!=t.top()) return false;
            s.pop();
            t.pop();
        }
        return s.empty() && t.empty();
    }
};

// Two Pointers:
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1;
        int j = T.size()-1;
        while (i>=0 && j>=0) {
            int base_s = 0;
            int base_t = 0;
            while (i>=0) {
                if (S[i]!='#' && base_s == 0) break;
                else S[i--]=='#'?base_s++:base_s--;
            }
            while (j>=0) {
                if (T[j]!='#' && base_t == 0) break;
                else T[j--]=='#'?base_t++:base_t--;
            }
            if (i>=0 && j>=0) {
                if (T[j]!=S[i]) return false;
                else { i--; j--; }
            } else break;
        }
        if (i>=0) {
            int base = 0;
            while (i>=0) {
                if (S[i]!='#' && base == 0) return false;
                else S[i--]=='#'?base++:base--;
            }
        }
        if (j>=0) {
            int base = 0;
            while (j>=0) {
                if (T[j]!='#' && base == 0) return false;
                else T[j--]=='#'?base++:base--;
            }
        }
        return true;
    }
};