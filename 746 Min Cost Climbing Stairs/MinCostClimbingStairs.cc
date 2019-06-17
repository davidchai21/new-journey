class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0;
        int second = 0;
        int cur = 0;
        for (int i=2;i<=cost.size();i++) {
            cur = min(cost[i-1]+second, cost[i-2]+first);
            first = second;
            second = cur;
        }
        return cur;
    }
};