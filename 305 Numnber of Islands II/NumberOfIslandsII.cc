class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int k = positions.size();
        vector<int> res(k);
        vector<int> record(k);
        vector<vector<int> > mp(m, vector<int>(n,-1));
        vector<int> dir = {1,0,-1,0,1};
        int count = 0;
        for (int i=0;i<k;i++) {
            int x = positions[i][0];
            int y = positions[i][1];
            if (mp[x][y]!=-1) {
                res[i]=count;
                continue;
            }
            record[i]=i;
            mp[x][y]=i;
            count++;
            for (int j=0;j<4;j++) {
                int _x = x+dir[j];
                int _y = y+dir[j+1];
                if (_x>=0 && _y>=0 && _x<m && _y<n && mp[_x][_y]!=-1) {
                    int parent = Find(mp[x][y], record);
                    int _parent = Find(mp[_x][_y], record);
                    if (parent != _parent) {
                        record[parent] = _parent;
                        count--;
                    }
                }
            }
            res[i]=count;
        }
        return res;
    }
private:
    int Find(int a, vector<int>& record) {
        if (a==record[a]) return a;
        record[a]=Find(record[a], record);
        return record[a];
    }
};