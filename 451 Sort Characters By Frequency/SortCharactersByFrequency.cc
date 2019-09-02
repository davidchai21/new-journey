class Solution {
public:
    string frequencySort(string s) {
        vector<string> record(s.size()+1,"");
        unordered_map<char, int> m;
        for (char c:s) m[c]++;
        for (unordered_map<char, int>::iterator it=m.begin();it!=m.end();it++) {
            record[it->second].append(it->second, it->first);
        }
        string res = "";
        for (int i=s.size();i>=0;i--) {
            if (!record[i].empty()) res+=record[i];
        }
        return res;
    }
};