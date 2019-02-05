class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t="";
        helper(n,n,t,res);
        return res;
    }
    
    void helper(int left, int right, string a, vector<string>& res) {
        if (left ==0 && right == 0) {
            res.push_back(a);
            return;
        }
        if (left<0 || right<0 || right<left) return;
        a+='(';
        helper(left-1, right, a, res);
        a.pop_back();
        a+=')';
        helper(left, right-1, a, res);
        a.pop_back();
    }
};