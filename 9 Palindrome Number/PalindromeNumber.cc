class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x!=0 && x%10 == 0)) return false;
        int first = x;
        int second = 0;
        while (first>second) {
            second = second *10 + first%10;
            first /= 10;
        }
        return first == second || first == second/10;
    }
};