class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int> > s;
        vector<vector<int> > res;
        for (vector<int> queen:queens) {
            s.insert(make_pair(queen[0], queen[1]));
        }
        for (int i=king[0]-1;i>=0;--i) {
            if (s.find(make_pair(i,king[1]))!=s.end()) {
                res.push_back({i,king[1]});
                break;
            }
        }
        for (int i=king[0]+1;i<8;++i) {
            if (s.find(make_pair(i,king[1]))!=s.end()) {
                res.push_back({i,king[1]});
                break;
            }
        }
        for (int i=king[1]-1;i>=0;--i) {
            if (s.find(make_pair(king[0],i))!=s.end()) {
                res.push_back({king[0],i});
                break;
            }
        }
        for (int i=king[1]+1;i<8;++i) {
            if (s.find(make_pair(king[0],i))!=s.end()) {
                res.push_back({king[0],i});
                break;
            }
        }
        for (int i=king[0]-1, j=king[1]-1; i>=0 && j>=0;--i,--j) {
            if (s.find(make_pair(i,j))!=s.end()) {
                res.push_back({i,j});
                break;
            }
        }
        for (int i=king[0]-1, j=king[1]+1; i>=0 && j<8;--i,++j) {
            if (s.find(make_pair(i,j))!=s.end()) {
                res.push_back({i,j});
                break;
            }
        }
        for (int i=king[0]+1, j=king[1]-1; i<8 && j>=0;++i,--j) {
            if (s.find(make_pair(i,j))!=s.end()) {
                res.push_back({i,j});
                break;
            }
        }
        for (int i=king[0]+1, j=king[1]+1; i<8 && j<8;++i,++j) {
            if (s.find(make_pair(i,j))!=s.end()) {
                res.push_back({i,j});
                break;
            }
        }
        return res;
    }
};