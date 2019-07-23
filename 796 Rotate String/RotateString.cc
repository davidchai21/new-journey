class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size()!=B.size()) return false;
        string whole = B+B;
        return whole.find(A)!=string::npos;
    }
};