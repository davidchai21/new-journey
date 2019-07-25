class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int dis = 1;
        while (candies>=dis) {
            res[(dis-1)%num_people]+=dis;
            candies-=dis++;
        }
        res[(dis-1)%num_people]+=candies;
        return res;
    }
};