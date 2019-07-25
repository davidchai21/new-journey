class Solution {
public:
    int numberOfDays(int Y, int M) {
        if (M == 1 || M == 3 || M == 7 || M == 8 || M == 5 || M == 10 || M == 12) return 31;
        if (M == 6 || M == 4 || M == 9 || M == 11) return 30;
        return Y%4?28:Y%100?29:Y%400?28:29;
    }
};