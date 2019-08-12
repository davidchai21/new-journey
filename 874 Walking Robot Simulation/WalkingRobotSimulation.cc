class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int> > obs;
        for (vector<int> a:obstacles) obs.insert(make_pair(a[0],a[1]));
        int index = 0;
        int x = 0;
        int y = 0;
        int res = 0;
        for (int command: commands) {
            if (command == -2) index = (index+3)%4;
            else if (command == -1) index = (index+1)%4;
            else {
                for (int i=0;i<command;i++) {
                    x+=dir[index].first;
                    y+=dir[index].second;
                    if (obs.find(make_pair(x,y))!=obs.end()) {
                        x-=dir[index].first;
                        y-=dir[index].second;
                        break;
                    }
                    res = max(res, x*x+y*y);
                }
            }
        }
        return res;
    }
private:
    vector<pair<int,int> > dir = {{0,1},{1,0},{0,-1},{-1,0}};
};