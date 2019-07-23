class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for (int a:nums1) m[a]++;
        vector<int> res;
        for (int a:nums2) {
            if (m[a]) {
                res.push_back(a);
                m[a]--;
            }
        }
        return res;
    }
};