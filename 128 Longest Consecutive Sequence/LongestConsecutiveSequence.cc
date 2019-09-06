class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (int n:nums) m[n]=1;
        for (int n:nums) {
            res = max(res, update(n));
        }
        return res;
    }
private:
    unordered_map<int,int> m;
    int update(int n) {
        if (m.find(n)==m.end()) return 0;
        if (m[n]==1) {
            m[n] = update(n+1)+1;
        }
        return m[n];
    }
};