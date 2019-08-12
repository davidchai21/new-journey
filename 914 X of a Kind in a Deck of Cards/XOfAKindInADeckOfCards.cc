class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;
        for (int d:deck) m[d]++;
        int common = -1;
        for (unordered_map<int,int>::iterator it=m.begin();it!=m.end();it++) {
            if (common == -1) common = it->second;
            else {
                common = gcd(max(common, it->second), min(common, it->second));
                if (common == 1) return false;
            }
        }
        return common>1;
    }
    
    int gcd(int x, int y) {
        if (x%y==0) return y;
        return gcd(y, x%y);
    }
};