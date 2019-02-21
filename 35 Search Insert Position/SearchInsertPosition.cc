class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || target>nums.back()) return nums.size();
        int i=0;
        while (nums[i]<target) i++;
        return i;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || nums.back()<target) return nums.size();
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            int mid = left+(right-left)/2;
            if (nums[mid]>target) right = mid;
            else if (nums[mid]<target) left = mid+1;
            else return mid;
        }
        return left;
    }
};