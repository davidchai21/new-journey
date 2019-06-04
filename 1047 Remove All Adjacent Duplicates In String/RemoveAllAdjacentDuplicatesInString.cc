class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for (char c:S) {
            if (s.empty() || s.top()!=c) s.push(c);
            else s.pop();
        }
        if (s.empty()) return "";
        string res(s.size(),'x');
        for (int i=s.size()-1;i>=0;i--) {
            res[i]=s.top();
            s.pop();
        }
        return res;
    }
};