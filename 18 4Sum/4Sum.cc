class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for (int i=0;i<nums.size()-3;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1;j<nums.size()-2;j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1;
                int right = nums.size()-1;
                while (left<right) {
                    if (nums[i]+nums[j]+nums[left]+nums[right] == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left<right && nums[left]==nums[left+1]) left++;
                        left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        right--;
                    } else if (nums[i]+nums[j]+nums[left]+nums[right] < target) {
                        while (left<right && nums[left]==nums[left+1]) left++;
                        left++;
                    } else {
                        while (left<right && nums[right]==nums[right-1]) right--;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};