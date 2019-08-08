class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int digit = 1;
        for (int i=0;i<digits.size();i++) {
            digit += digits[i];
            digits[i]=digit%10;
            digit/=10;
            if (digit == 0) break;
        }
        if (digit) digits.push_back(digit);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};