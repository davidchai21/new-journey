class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num1=="0") return num2;
        if (num2.empty() || num2=="0") return num1;
        string res = "";
        int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        int digit = 0;
        while (p1>=0 || p2>=0 || digit) {
            if (p1>=0) digit += num1[p1--]-'0';
            if (p2>=0) digit += num2[p2--]-'0';
            res = to_string(digit%10)+res;
            digit /=10;
        }
        return res;
    }
};