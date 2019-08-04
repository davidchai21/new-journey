class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> m;
        for (int n:nums) m[n]++;
        for (unordered_map<int,int>::iterator it = m.begin();it!=m.end();it++) {
            if (m.find(it->first+1)!=m.end()) res = max(res, it->second+m[it->first+1]);
        }
        return res;
    }
};