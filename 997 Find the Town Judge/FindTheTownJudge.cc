class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<pair<int,bool> > m(N,make_pair(0,true));
        int res = -1;
        for (vector<int> a:trust) {
            m[a[1]-1].first++;
            m[a[0]-1].second = false;
        }
        for (int i=0;i<m.size();i++) {
            if (m[i].first == N-1 && m[i].second==true) {
                if (res == -1) res = i+1;
                else return -1;
            }
        }
        return res;
    }
};