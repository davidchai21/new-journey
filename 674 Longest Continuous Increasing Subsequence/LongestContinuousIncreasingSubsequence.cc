class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int res = 1;
        int base = 1;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]>nums[i-1]) base++;
            else {
                res = max(res, base);
                base = 1;
            }
        }
        res = max(res, base);
        return res;
    }
};