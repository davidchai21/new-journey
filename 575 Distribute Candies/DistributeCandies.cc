class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        for (int candy: candies) m[candy]++;
        return min(candies.size()/2, m.size());
    }
};