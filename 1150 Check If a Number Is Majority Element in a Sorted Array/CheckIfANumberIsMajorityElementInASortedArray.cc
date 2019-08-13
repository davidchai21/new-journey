class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if (nums[nums.size()/2]!=target) return false;
        int left = 0;
        int right = 0;
        int i=0;
        int j=nums.size()-1;
        while (i+1<j) {
            int mid = i+(j-i)/2;
            if (nums[mid]<target) i=mid;
            else j=mid;
        }
        left = nums[i]==target?i:j;
        i = 0;
        j = nums.size()-1;
        while (i+1<j) {
            int mid = i+(j-i)/2;
            if (nums[mid]>target) j=mid;
            else i=mid;
        }
        right = nums[j]==target?j:i;
        return right-left+1>nums.size()/2;
    }
};