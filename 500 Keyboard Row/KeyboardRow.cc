class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (string a:words) {
            if (check(a)) res.push_back(a);
        }
        return res;
    }
private:
    vector<vector<char> > dic = {
        {'q','w','e','r','t','y','u','i','o','p'},
        {'a','s','d','f','g','h','j','k','l'},
        {'z','x','c','v','b','n','m'}
    };
    
    bool check(string a) {
        int id = -1;
        for (int i=0;i<dic.size();i++) {
            for (int j=0;j<dic[i].size();j++) {
                if (dic[i][j]==tolower(a[0])) {
                    id = i;
                    i = 3;
                    break;
                }
            }
        }
        for (int i=1;i<a.size();i++) {
            int j=0;
            while (j<dic[id].size()) {
                if (tolower(a[i])==dic[id][j]) break;
                j++;
            }
            if (j==dic[id].size()) return false;
        }
        return true;
    }
};