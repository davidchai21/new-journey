class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = nums[0];
        for (int n:nums) minNum = min(minNum, n);
        int res = 0;
        for (int n:nums) res += n-minNum;
        return res;
    }
};