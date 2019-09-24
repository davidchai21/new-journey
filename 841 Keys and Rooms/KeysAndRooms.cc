class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int opened = rooms.size()-1;
        vector<bool> visited(rooms.size(),false);
        visited[0]=true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int k:rooms[cur]) {
                if (!visited[k]) {
                    visited[k]=true;
                    q.push(k);
                    --opened;
                }
            }
        }
        return !opened;
    }
};