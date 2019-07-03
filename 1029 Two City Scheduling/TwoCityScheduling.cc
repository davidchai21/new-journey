class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int> > mapping(costs.size());
        for (int i=0;i<costs.size();i++) {
            mapping[i]=make_pair(i, costs[i][0]-costs[i][1]);
        }
        sort(mapping.begin(), mapping.end(), [](pair<int,int>& a, pair<int,int>& b){return a.second<b.second;});
        int res = 0;
        int i=0;
        for (;i<costs.size()/2;i++) res += costs[mapping[i].first][0];
        for (;i<costs.size();i++) res += costs[mapping[i].first][1];
        return res;
    }
};