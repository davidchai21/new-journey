class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res(2);
        m[nums[0]]=0;
        for (int i=1;i<nums.size();i++) {
            if (m.find(target-nums[i])!=m.end()) {
                res[0]=m[target-nums[i]];
                res[1]=i;
                return res;
            }
            else {
                m[nums[i]]=i;
            }
        }
    }
};