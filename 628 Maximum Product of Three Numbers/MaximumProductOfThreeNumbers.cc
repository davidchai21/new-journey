class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int l1 = INT_MIN;   // l1>l2>l3;
        int l2 = INT_MIN;
        int l3 = INT_MIN;
        int s1 = INT_MAX;    // s1<s2
        int s2 = INT_MAX;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]>l1) {
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            } else if (nums[i]>l2) {
                l3 = l2;
                l2 = nums[i];
            } else if (nums[i]>l3) {
                l3 = nums[i];
            }
            if (nums[i]<s1) {
                s2 = s1;
                s1 = nums[i];
            } else if (nums[i]<s2) {
                s2 = nums[i];
            }
        }
        return max(l1*l2*l3, s1*s2*l1);
    }
};