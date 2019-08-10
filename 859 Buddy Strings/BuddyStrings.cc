class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size()!=B.size()) return false;
        vector<int> record(26,0);
        bool flag = false;
        for (char a:A) {
            record[a-'a']++;
            if (record[a-'a']>1) flag = true;
        }
        if (A==B) return flag;
        for (char b:B) record[b-'a']--;
        for (int i:record) {
            if (i) return false;
        }
        int count = 0;
        for (int i=0;i<A.size();i++) {
            if (A[i]!=B[i]) count++;
            if (count>2) return false;
        }
        return true;
    }
};