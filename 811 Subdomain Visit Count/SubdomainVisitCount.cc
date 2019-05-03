class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        if (cpdomains.empty()) return {};
        unordered_map<string, int> m;
        for (int i=0;i<cpdomains.size();i++) {
            addDom(cpdomains[i], m);
        }
        vector<string> res;
        for (auto it = m.begin();it!=m.end();it++) {
            res.push_back(to_string(it->second)+" "+it->first);
        }
        return res;
    }
    
    void addDom(string a, unordered_map<string, int>& m) {
        int i=0;
        int count = 0;
        while (a[i]!=' ') {
            count = count*10+a[i++]-'0';
        }
        int j=a.size()-1;
        while (j>i) {
            while (j>i && a[j]!='.') j--;
            m[a.substr(j--+1)]+=count;
        }
    }
};