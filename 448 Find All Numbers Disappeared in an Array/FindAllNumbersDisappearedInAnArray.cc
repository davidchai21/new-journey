class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            while (nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            if (i+1!=nums[i]) res.push_back(i+1);
        }
        return res;
    }
};