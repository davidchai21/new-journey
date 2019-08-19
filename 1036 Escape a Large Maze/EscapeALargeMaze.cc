class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int res = helper(blocked, source, target);
        if (res==-1) return true;
        if (res==0) return false;
        return helper(blocked, target, source);
    }
    
    int helper(vector<vector<int> >& blocked, vector<int>& vec, vector<int>& target) {
        unordered_map<int, unordered_set<int> > m;
        for (vector<int> b:blocked) m[b[0]].insert(b[1]);
        queue<pair<int,int> > q;
        q.push(make_pair(vec[0], vec[1]));
        for (int i=0;i<200;i++) {
            if (q.empty()) return 0;
            int n=q.size();
            for (int j=0;j<n;j++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k=0;k<4;k++) {
                    int s = x+dir[k].first;
                    int t = y+dir[k].second;
                    if (s>=0 && t>=0 && s<1000000 && t <1000000 && m[s].find(t)==m[s].end()) {
                        if (s==target[0]&& t==target[1]) return -1;
                        m[s].insert(t);
                        q.push(make_pair(s,t));
                    }
                }
            }
        }
        return 1;
    }
private:
    vector<pair<int,int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
};