// Traditional:
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size()-needle.size()+1;
        for (int i=0;i<n;i++) {
            if (check(haystack, needle, i)) return i;
        }
        return -1;
    }
    
    bool check(string a, string b, int x) {
        for (int i=0;i<b.size();i++) {
            if (a[i+x]!=b[i]) return false;
        }
        return true;
    }
};

// KMP:
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.size()>haystack.size()) return -1;
        vector<int> lps = getArray(needle);
        int index = 0;
        for (int i=0;i<haystack.size();) {
            if (haystack[i]==needle[index]) {
                index++;
                i++;
                if (index == needle.size()) return i-index;
            } else {
                if (index) index = lps[index-1];
                else i++;
            }
        }
        return -1;
    }
    
    vector<int> getArray(string str) {
        int n=str.size();
        vector<int> lps(n,0);
        int len = 0;
        for (int i=1;i<n;) {
            if (str[i]==str[len]) lps[i++]=++len;
            else {
                if (len) len=lps[len-1];
                else lps[i++]=0;
            }
        }
        return lps;
    }
};