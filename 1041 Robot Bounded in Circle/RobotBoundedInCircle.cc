class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int index = 0;
        for (char a:instructions) {
            if (a=='G') {
                x+=dir[index][0];
                y+=dir[index][1];
            } else if (a=='L') index = (index+4-1)%4;
            else index = (index+1)%4;
        }
        return !x&&!y || index;
    }
    
private:
    vector<vector<int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
};