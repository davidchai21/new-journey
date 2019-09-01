// BFS:
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> indegree(numCourses,0);
        for (vector<int> pre:prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++) {
            if (!indegree[i]) q.push(i);
        }
        while (!q.empty()) {
            vector<int> cur = graph[q.front()];
            q.pop();
            for (int i=0;i<cur.size();i++) {
                if (--indegree[cur[i]]==0) q.push(cur[i]);
            }
            numCourses--;
        }
        return numCourses==0;
    }
};

// vector:
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        for (vector<int> a:prerequisites) graph[a[1]].push_back(a[0]);
        vector<int> indegree(numCourses,0);
        for (int i=0;i<numCourses;i++) {
            for (int j=0;j<graph[i].size();j++) {
                indegree[graph[i][j]]++;
            }
        }
        for (int i=0;i<numCourses;i++) {
            int j=0;
            for (;j<numCourses;j++) {
                if (indegree[j]==0) break;
            }
            if (j==numCourses) return false;
            indegree[j]=-1;
            for (int k=0;k<graph[j].size();k++) {
                indegree[graph[j][k]]--;
            }
        }
        return true;
    }
};