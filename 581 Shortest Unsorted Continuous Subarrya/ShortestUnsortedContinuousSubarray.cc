class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = INT_MAX;
        int right = INT_MIN;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]<nums[i-1]) {
                int j=min(i-1, left);
                while (j>=0 && nums[i]<nums[j]) j--;
                left = min(left, j+1);
                if (j<0) break;
            }
        }
        for (int i=nums.size()-2;i>=0;i--) {
            if (nums[i]>nums[i+1]) {
                int j=max(right, i+1);
                while (j<nums.size() && nums[i]>nums[j]) j++;
                right = max(right, j-1);
                if (j>=nums.size()) break;
            }
        }
        return left == INT_MAX?0:right-left+1;
    }
};