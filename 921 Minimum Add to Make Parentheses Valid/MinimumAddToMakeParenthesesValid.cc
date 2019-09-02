class Solution {
public:
    int minAddToMakeValid(string S) {
        int num = 0;
        int res = 0;
        stack<char> s;
        for (int i=0;i<S.size();i++) {
            if (S[i]=='(') {
                if (num>=0) num++;
                else {
                    res+=-num;
                    num=1;
                }
            } else {
                num--;
            }
        }
        res+=abs(num);
        return res;
    }
};