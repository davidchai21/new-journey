class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> dic(26);
        for (int i=0;i<26;i++) {
            dic[keyboard[i]-'a']=i;
        }
        int res = 0;
        int pre = 0;
        for (char c:word) {
            res += abs(dic[c-'a']-pre);
            pre = dic[c-'a'];
        }
        return res;
    }
};