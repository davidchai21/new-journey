class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res(queries.size());
        for (int i=0;i<values.size();i++) {
            Union(equations[i][0], equations[i][1], values[i]);
        }
        for (int i=0;i<queries.size();i++) {
            if (m.find(queries[i][0])==m.end() || m.find(queries[i][1])==m.end()) res[i]=-1.0;
            else if (queries[i][0]==queries[i][1]) res[i]=1.0;
            else {
                pair<string, double> pa = Find(queries[i][0]);
                pair<string, double> pb = Find(queries[i][1]);
                if (pa.first != pb.first) res[i] = -1.0;
                else res[i]=pb.second/pa.second;
            }
        }
        return res;
    }
private:
    unordered_map<string, pair<string, double> > m;
    pair<string, double> Find(string a) {
        if (m.find(a)==m.end()) {
            m[a] = make_pair(a,1.0);
            return m[a];
        }
        if (m[a].first == a) return m[a];
        pair<string, double> t = Find(m[a].first);
        m[a] = make_pair(t.first, t.second*m[a].second);
        return m[a];
    }
    
    bool Union(string a, string b, double val) {
        pair<string, double> pa = Find(a);
        pair<string, double> pb = Find(b);
        if (pa.first == pb.first) return false;
        m[pb.first] = make_pair(pa.first, val*pa.second/pb.second);
        return true;
    }
};