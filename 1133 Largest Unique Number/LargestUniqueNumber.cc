class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int,int> m;
        for (int a:A) m[a]++;
        int res = -1;
        for (unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++) {
            if (it->second==1 && it->first>res) res = it->first;
        }
        return res;
    }
};