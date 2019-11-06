class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0] || a[0]==b[0] && a[1]<b[1];});
        vector<vector<int> > res(people.size(), vector<int>());
        for (int k=0;k<people.size();++k) {
            int index = people[k][1];
            for (int i=0;i<people.size();++i) {
                if (res[i].empty()) {
                    if (index) --index;
                    else {
                        res[i]=people[k];
                        break;
                    }
                } else {
                    if (res[i][0]==people[k][0]) --index;
                }
            }
        }
        return res;
    }
};