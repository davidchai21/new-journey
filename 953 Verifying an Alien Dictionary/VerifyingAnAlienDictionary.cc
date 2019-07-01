class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1) return true;
        vector<int> table(26,-1);
        
        for (int i=0;i<order.size();i++) {
            table[order[i]-'a'] = i;
        }
        
        for (int i=0;i<words.size()-1;i++) {
            if (!compare2(words[i], words[i+1], table)) return false;
        }
        return true;
    }
    
    bool compare2(string a, string b, vector<int>& table) {
        int len = min(a.size(), b.size());
        for (int i=0;i<len; i++) {
            if (table[a[i]-'a']<table[b[i]-'a']) return true;
            else if (table[a[i]-'a']>table[b[i]-'a']) return false;
        }
        return a.size() == b.size();
    }
};