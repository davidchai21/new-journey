class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums.back();
        if (nums.size()>3) {
            for (int i=0;i<nums.size()-1;i++) {
                int left = i+1;
                int right = nums.size()-1;
                int t = 0;
                while (left < right) {
                    t = nums[i] + nums[left] + nums[right];
                    res = (abs(t-target)>abs(res-target))?res:t;
                    if (t<target) left++;
                    else if (t>target) right--;
                    else return target;
                }
            }
        }
        return res;
    }
};