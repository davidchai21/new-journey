class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0;i<nums.size();i++) {
            res += i+1-nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0]^1;
        for (int i=1;i<nums.size();i++) {
            res ^= (i+1)^nums[i];
        }
        return res;
    }
};