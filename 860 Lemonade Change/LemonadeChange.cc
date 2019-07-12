class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills.empty()) return true;
        if (bills[0]!=5) return false;
        int five = 0;
        int ten = 0;
        for (int i=0;i<bills.size();i++) {
            if (bills[i]==5) five++;
            else if (bills[i]==10) {
                ten++;
                if (five) five--;
                else return false;
            } else {
                if (ten) {
                    ten--;
                    if (five) five--;
                    else return false;
                } else if (five>2) {
                    five = five-3;
                } else return false;
            }
        }
        return true;
    }
};