class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dic(256,0);
        for (char a:magazine) dic[a]++;
        for (char a:ransomNote) {
            dic[a]--;
            if (dic[a]<0) return false;
        }
        return true;
    }
};