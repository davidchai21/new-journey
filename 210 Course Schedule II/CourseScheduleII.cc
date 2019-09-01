class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for (vector<int> p:prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (!indegree[i]) q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            numCourses--;
            res.push_back(cur);
            for (int i=0;i<graph[cur].size();i++) {
                if (--indegree[graph[cur][i]]==0) q.push(graph[cur][i]);
            }
        }
        if (numCourses) res = {};
        return res;
    }
};