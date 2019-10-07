class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() ==1 || nums.back()!=nums[nums.size()-2]) return nums.back();
        int left = 0;
        int right = (nums.size()-1)/2;
        while (left + 1<right) {
            int mid = left + (right-left)/2;
            if (nums[2*mid]==nums[2*mid+1]) left = mid+1;
            else right = mid;
        }
        if (nums[left*2]!=nums[left*2+1]) return nums[left*2];
        return nums[right*2];
    }
};