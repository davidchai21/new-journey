class Solution {
public:
    int reachNumber(int target) {
        if (target == 0) return 0;
        if (target<0) return reachNumber(-target);
        int sum = 0;
        int step =1;
        while (sum<target) {
            sum+=step;
            step++;
        }
        while (sum%2!=target%2) {
            sum+=step;
            step++;
        }
        return step-1;
    }
};