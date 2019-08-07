class Solution {
public:
    bool isStrobogrammatic(string num) {
        for (int i=0;i<=num.size()/2;i++) {
            int x = num[i]-'0';
            int y = num[num.size()-1-i]-'0';
            if (x==0 && y==0 || x==1 && y==1 || x==6 && y==9 || x==8 && y==8 || x==9 && y==6) continue;
            else return false;
        }
        return true;
    }
};