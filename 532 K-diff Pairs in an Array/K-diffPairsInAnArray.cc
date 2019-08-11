class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k<0) return 0;
        unordered_map<int, int> m;
        for (int i:nums) m[i]++;
        int res = 0;
        if (k==0) {
            for (unordered_map<int, int>::iterator it = m.begin();it!=m.end();it++) {
                if (it->second>1) res++;
            }
        } else {
            for (unordered_map<int, int>::iterator it = m.begin();it!=m.end();it++) {
                if (m.find(it->first+k)!=m.end()) res++;
            }
        }
        return res;
    }
};