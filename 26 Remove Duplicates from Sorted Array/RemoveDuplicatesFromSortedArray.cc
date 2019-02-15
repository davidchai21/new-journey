class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int i=0;
        for (int j=0;j<nums.size();j++) {
            if (nums[j]!=nums[i]) {
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
};