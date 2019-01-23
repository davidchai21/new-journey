class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i=0;
        int sign = 1;
        while (i<str.size() && str[i] == ' ') i++;
        if (i == str.size()) return 0;
        else if (str[i] == '+' || str[i]=='-' || isdigit(str[i])) {
            // do sth
            if (!isdigit(str[i])) {
                if (str[i] == '-') sign = -1;
                i++;
            } 
            while (i<str.size() && isdigit(str[i])) {
                int d = str[i]-'0';
                if (sign == 1 && (res>INT_MAX/10 ||(res == INT_MAX/10 && d>INT_MAX%10))) return INT_MAX;
                if (sign == -1 && (-res<INT_MIN/10 ||(-res == INT_MIN/10 && -d<INT_MIN%10))) return INT_MIN;
                res = res*10 + d;
                i++;
            }
            return (sign == 1)?res:-res;
        }
        return 0;
    }
};