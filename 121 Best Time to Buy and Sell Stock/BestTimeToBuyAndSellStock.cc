class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int res = 0;
        int low = prices[0];
        int high = prices[0];
        for (int i=1;i<prices.size();i++) {
            if (prices[i]<low) {
                low = prices[i];
                high = prices[i];
            } else if (prices[i]>high) {
                high = prices[i];
                res = max(res, high - low);
            }
        }
        return max(res, high - low);
    }
};