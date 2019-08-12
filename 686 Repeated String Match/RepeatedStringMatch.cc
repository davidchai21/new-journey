class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int times = B.size()/A.size();
        if (times*A.size()<B.size()) times++;
        string str = "";
        for (int i=0;i<times;i++) str += A;
        if (str.find(B)!=string::npos) return times;
        else {
            str+=A;
            if (str.find(B)!=string::npos) return times+1;
        }
        return -1;
    }
};