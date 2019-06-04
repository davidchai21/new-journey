class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        else if (stones.size()==1) return stones[0];
        priority_queue<int> q;
        for (int stone:stones) {
            q.push(stone);
        }
        while (q.size()>1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push(abs(x-y));
        }
        return q.top();
    }
};