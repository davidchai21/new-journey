class Solution {
public:
    int tribonacci(int n) {
        int T_one = 0;
        int T_two = 1;
        int T_three = 1;
        if (n==0) return T_one;
        if (n==1) return T_two;
        if (n==2) return T_three;
        for (int i=2;i<n;i++) {
            int t = T_one+T_two+T_three;
            T_one = T_two;
            T_two = T_three;
            T_three = t;
        }
        return T_three;
    }
};