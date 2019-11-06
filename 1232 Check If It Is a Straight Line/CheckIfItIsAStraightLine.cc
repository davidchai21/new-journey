class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size()==2) return true;
        if (coordinates[0][0]==coordinates[1][0]) {
            for (int i=2;i<coordinates.size();++i) {
                if (coordinates[i][0]!=coordinates[0][0]) return false;
            }
            return true;
        }
        if (coordinates[0][1]==coordinates[1][1]) {
            for (int i=2;i<coordinates.size();++i) {
                if (coordinates[i][1]!=coordinates[0][1]) return false;
            }
            return true;
        }
        double k = (double)(coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
        for (int i=2;i<coordinates.size();++i) {
            double m = coordinates[i][0]-coordinates[0][0];
            if (m==0.0) return false;
            double t = (coordinates[i][1]-coordinates[0][1])/m;
            if (t!=k) return false;
        }
        return true;
    }
};