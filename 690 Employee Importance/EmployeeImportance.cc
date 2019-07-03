/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int> > > m;
        for (int i=0;i<employees.size();i++) {
            m[employees[i]->id] = make_pair(employees[i]->importance, employees[i]->subordinates);
        }
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int tid = q.front();
            q.pop();
            res += m[tid].first;
            for (int ttid: m[tid].second) q.push(ttid);
        }
        return res;
    }
};