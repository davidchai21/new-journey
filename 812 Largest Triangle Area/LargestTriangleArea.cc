class Solution {
public:
    double getSize(vector<int>& a, vector<int>& b, vector<int>& c) {
        return abs((a[0]*b[1]-a[1]*b[0]+b[0]*c[1]-b[1]*c[0]+c[0]*a[1]-c[1]*a[0])/2.0);
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        double size = 0;
        for (int i=0;i<points.size()-2;i++) {
            for (int j=i+1;j<points.size()-1;j++) {
                for (int k=j+1;k<points.size();k++) {
                    size = max(size, getSize(points[i], points[j], points[k]));
                }
            }
        }
        return size;
    }
};