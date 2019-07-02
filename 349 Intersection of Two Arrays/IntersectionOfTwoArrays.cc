class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        
        for (int a:nums1) s.insert(a);
        for (int a:nums2) {
            if (s.find(a)!=s.end()) {
                res.push_back(a);
                s.erase(a);
            }
        }
        return res;
    }
};