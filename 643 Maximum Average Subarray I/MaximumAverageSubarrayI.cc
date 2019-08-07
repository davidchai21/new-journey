class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i=0;i<k;i++) sum+=nums[i];
        double res = sum;
        for (int i=0;i<nums.size()-k;i++) {
            sum += nums[i+k]-nums[i];
            res = max(res, sum);
        }
        return res/k;
    }
};