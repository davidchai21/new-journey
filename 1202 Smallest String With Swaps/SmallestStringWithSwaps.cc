class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> record(s.size());
        iota(record.begin(), record.end(),0);
        for (vector<int>& p:pairs) {
            Union(p[0], p[1], record);
        }
        unordered_map<int, string> m;
        for (int i=0;i<s.size();i++) {
            int parent = Find(i, record);
            m[parent] += s[i];
        }
        unordered_map<int, int> index;
        for (unordered_map<int, string>::iterator it=m.begin(); it!=m.end(); it++) {
            sort(it->second.begin(), it->second.end());
            index[it->first] = 0;
        }
        string res="";
        for (int i=0;i<s.size();i++) {
            int parent = Find(i, record);
            res += m[parent][index[parent]++];
        }
        return res;
    }
private:
    int Find(int a, vector<int>& record) {
        if (a==record[a]) return a;
        record[a]=Find(record[a], record);
        return record[a];
    }
    
    bool Union(int a, int b, vector<int>& record) {
        int pa = Find(a, record);
        int pb = Find(b, record);
        if (pa==pb) return false;
        record[pa] = pb;
        return true;
    }
};