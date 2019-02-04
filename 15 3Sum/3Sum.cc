class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size()<3) return vector<vector<int> >{};
        sort(nums.begin(), nums.end());
        if (nums[0]>0 || nums.back()<0) return {};
        set<vector<int> > s;
        vector<vector<int> > res;
        for (int i=0;i<nums.size()-2;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while (left < right) {
                if (nums[i]+nums[left]+nums[right]<0) {
                    int t=nums[left];
                    while (left<right && nums[left]==t) left++;
                } else if (nums[i]+nums[left]+nums[right]>0) {
                    int t=nums[right];
                    while (left<right && nums[right]==t) right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left<right && nums[left]==res.back()[1]) left++;
                    while (left<right && nums[right]==res.back()[2]) right--;
                }
            }
        }
        return res;
    }
};