class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<unordered_map<int,int> > m(points.size());
        for (int i=0;i<points.size()-1;i++) {
            for (int j=i+1;j<points.size();j++) {
                int dis = getDis(points[i], points[j]);
                m[i][dis]++;
                m[j][dis]++;
            }
        }
        int res = 0;
        for (unordered_map<int,int> mp:m) {
            for (auto it=mp.begin();it!=mp.end();it++) {
                res+=it->second*(it->second-1);
            }
        }
        return res;
    }
    
    int getDis(vector<int> a, vector<int> b) {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};