class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==1) count++;
            else {
                res = max(res, count);
                count = 0;
            }
        }
        res = max(res,count);
        return res;
    }
};