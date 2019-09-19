class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (vector<string>& account:accounts) {
            for (int i=1;i<account.size();i++) {
                name[account[i]] = account[0];
                parent[account[i]]=account[i];
            }
        }
        for (vector<string>& account:accounts) {
            string p = Find(account[1]);
            for (int i=2;i<account.size();i++) {
                parent[Find(account[i])] = p;
            }
        }
        for (vector<string>& account:accounts) {
            for (int i=1;i<account.size();i++) {
                Union(account[i]);
            }
        }
        vector<vector<string> > res;
        for (unordered_map<string, unordered_set<string> >::iterator it=record.begin();it!=record.end();it++) {
            vector<string> t;
            t.push_back(name[it->first]);
            for (auto iit = it->second.begin(); iit!=it->second.end();iit++) {
                t.push_back(*iit);
            }
            sort(t.begin(), t.end());
            res.push_back(t);
        }
        return res;
    }
private:
    unordered_map<string, string> name; // email's name
    unordered_map<string, string> parent; // email's ancestor
    unordered_map<string, unordered_set<string> > record;
    string Find(string& a) {
        if (parent[a]==a) return a;
        parent[a] = Find(parent[a]);
        return parent[a];
    }
    void Union(string& a) {
        record[Find(a)].insert(a);
    }
};