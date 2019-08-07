class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> record(256,-1);
        for (int i=0;i<s.size();i++) {
            if (record[s[i]]==-1) record[s[i]]=t[i];
            else {
                if (record[s[i]]!=t[i]) return false;
            }
        }
        sort(record.begin(), record.end());
        for (int i=1;i<record.size();i++) {
            if (record[i-1]==-1) continue;
            if (record[i]==record[i-1]) return false;
        }
        return true;
    }
};