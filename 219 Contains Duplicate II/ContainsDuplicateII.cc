class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k<1) return false;
        unordered_set<int> s;
        for (int i=0;i<k && i<nums.size();i++) {
            if (s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
        }
        for (int i=k;i<nums.size();i++) {
            if (s.find(nums[i])!=s.end()) return true;
            s.erase(nums[i-k]);
            s.insert(nums[i]);
        }
        return false;
    }
};

// using unordered_map, storing index, much better
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) {
            if (m.find(nums[i])!=m.end() && i-m[nums[i]]<=k) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};