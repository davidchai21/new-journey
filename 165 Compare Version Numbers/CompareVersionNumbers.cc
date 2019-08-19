class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1<version1.size() || index2<version2.size()) {
            int ver1 = getNext(version1, index1);
            int ver2 = getNext(version2, index2);
            if (ver1>ver2) return 1;
            else if (ver2>ver1) return -1;
        }
        return 0;
    }
    
    int getNext(string str, int& index) {
        int res = 0;
        if (index>=str.size()) return res;
        int j=index+1;
        while (j<str.size() && str[j]!='.') j++;
        for (;index<j;index++) {
            res = res*10+str[index]-'0';
        }
        if (index<str.size() && str[index]=='.') index++;
        return res;
    }
};