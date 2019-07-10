class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int> > m;
        for (int i=0;i<nums.size();i++) {
            m[nums[i]].push_back(i);
        }
        int size = 0;
        int res = 0;
        for (auto it = m.begin();it!=m.end();it++) {
            if (it->second.size()>size) {
                size = it->second.size();
                res = it->second.back()-it->second[0]+1;
            } else if (it->second.size() == size) {
                res = min(res, it->second.back()-it->second[0]+1);
            }
        }
        return res;
    }
};