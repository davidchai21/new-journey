class Solution {
public:
    string toHex(int num) {
        if (num==0) return "0";
        int count = 0;
        string res = "";
        while (num && count++<8) {
            res = dic[num&0xf] + res;
            num>>=4;
        }
        return res;
    }
private:
    string dic = "0123456789abcdef";
};