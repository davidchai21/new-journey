class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i=0;i<nums.size();i++) {
            if (i-1>=0) leftSum+=nums[i-1];
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};