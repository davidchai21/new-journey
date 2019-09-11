class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> dic(26);
        iota(dic.begin(), dic.end(), 0);
        sort(equations.begin(), equations.end(), [](string& a, string& b){return a[1]=='='&&b[1]=='!';});
        for (string a:equations) {
            if (!Union(a[0]-'a', a[3]-'a', dic, a[1]=='=')) return false;
        }
        return true;
    }
private:
    int Find(int a, vector<int>& dic) {
        if (dic[a]==a) return a;
        dic[a]=Find(dic[a], dic);
        return dic[a];
    }
    
    bool Union(int a, int b, vector<int>& dic, bool equal) {
        int pa = Find(a, dic);
        int pb = Find(b, dic);
        if (!equal && pa == pb) return false;
        else if (equal && pa != pb) dic[pa]=pb;
        return true;
    }
};