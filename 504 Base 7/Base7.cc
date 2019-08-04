class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        return (num<0?"-":"")+helper(abs(num));
    }
    
    string helper(int n) {
        string res = "";
        while (n) {
            int d = n%7;
            res = to_string(d)+res;
            n/=7;
        }
        return res;
    }
};