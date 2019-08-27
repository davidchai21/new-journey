class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if (m<2 || n<2) return 0;
        unordered_map<string, int> s;
        int res = 0;
        for (int i=0;i<m;i++) {
            vector<int> t;
            for (int j=0;j<n;j++) {
                if (grid[i][j]) t.push_back(j);
            }
            if (t.size()>1) {
                for (int i=0;i<t.size()-1;i++) {
                    for (int j=i+1;j<t.size();j++) {
                        string str = to_string(t[i])+","+to_string(t[j]-t[i]);
                        if (s.find(str)!=s.end()) res+=s[str];
                        s[str]++;
                    }
                }
            }
        }
        return res;
    }
};