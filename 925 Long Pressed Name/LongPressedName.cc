class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i<name.size() && j<typed.size()) {
            if (name[i]!=typed[j]) return false;
            if (i<name.size()-1 && name[i]==name[i+1]) { i++; j++; continue; }
            while (j<typed.size() && typed[j]==name[i]) j++;
            i++;
        }
        return j==typed.size() && i==name.size();
    }
};