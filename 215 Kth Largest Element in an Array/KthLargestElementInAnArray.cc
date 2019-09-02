class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = -1;
        int left = 0;
        int right = nums.size()-1;
        while (1) {
            int index = partition(nums, left, right);
            if (index == k-1) {
                res = nums[index];
                break;
            } else if (index>=k) {
                right = index-1;
            } else {
                left = index+1;
            }
        }
        return res;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        while (l<=r) {
            if (pivot>nums[l] && pivot<nums[r]) {
                swap(nums[l++], nums[r--]);
            }
            if (pivot<=nums[l]) { l++; }
            if (pivot>=nums[r]) { r--; }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

// C++ STL nth_element():
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};