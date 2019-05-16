class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<vector<vector<int> >, int> m;
        for (string a:A) {
            m[getVec(a)]++;
        }
        return m.size();
    }
    
    vector<vector<int> > getVec(string a) {
        vector<int> odd(26,0);
        vector<int> even(26,0);
        for (int i=0;i<a.size();i++) {
            if (i%2) {
                odd[a[i]-'a']++;
            } else {
                even[a[i]-'a']++;
            }
        }
        return {odd, even};
    }
};