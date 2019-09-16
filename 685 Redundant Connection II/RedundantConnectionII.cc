class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> record(n+1);
        iota(record.begin(), record.end(), 0);
        int counter = hasDoubleParent(edges);
        if (counter == -1) {
            for (vector<int>& edge:edges) {
                int px = Find(edge[0], record);
                int py = Find(edge[1], record);
                if (px == py) return edge;
                record[py] = px;
            }
        } else {
            vector<vector<int> > res;
            for (int i=0;i<n;i++) {
                if (edges[i][1]==counter) res.push_back(edges[i]);
            }
            for (int i=0;i<n;i++) {
                if (edges[i] == res[1]) continue;
                int px = Find(edges[i][0], record);
                int py = Find(edges[i][1], record);
                if (px == py) return res[0];
                record[py] = px;
            }
            return res[1];
        }
        return {};
    }
private:
    int hasDoubleParent(vector<vector<int> >& edges) {
        unordered_set<int> s;
        for (vector<int>& edge:edges) {
            if (s.find(edge[1])!=s.end()) return edge[1];
            s.insert(edge[1]);
        }
        return -1;
    }
    int Find(int a, vector<int>& record) {
        if (a==record[a]) return a;
        record[a] = Find(record[a], record);
        return record[a];
    }
};