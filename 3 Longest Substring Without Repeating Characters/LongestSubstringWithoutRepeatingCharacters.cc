class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256,-1);
        int front=-1;
        int end=0;
        int res=0;
        while (end<s.size()) {
            if (m[s[end]]!=-1) {
                front=max(front, m[s[end]]);
                m[s[end]]=end;
            } else {
                m[s[end]]=end;
            }
            res=max(res, end++-front);
        }
        return res;
    }
};