class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums.back();
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int first = nums[0];
        int second = max(nums[1], nums[0]);
        for (int i=2;i<nums.size();i++) {
            int t = max(first + nums[i], second);
            first = second;
            second = t;
        }
        return second;
    }
};