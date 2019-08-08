class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() ==1 ) return 0;
        int first = -1;
        int second = -1;
        int index = -1;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]>=first) {
                second = first;
                first = nums[i];
                index = i;
            }
            else if (nums[i]>second) second = nums[i];
        }
        return (first<2*second || second == -1)?-1:index;
    }
};