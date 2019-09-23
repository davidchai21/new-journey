class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = pow(2,tiles.size());
        int res = 0;
        sort(tiles.begin(), tiles.end());
        unordered_set<string> record;
        for (int i=1;i<n;i++) {
            string t = "";
            int bit = i;
            for (int j=tiles.size()-1;j>=0;j--) {
                if (bit&1) t = tiles[j]+t;
                bit>>=1;
            }
            record.insert(t);
        }
        for (unordered_set<string>::iterator it = record.begin(); it!=record.end();it++) {
            res += helper(*it);
        }
        return res;
    }
private:
    int fac(int n) {
        int res = 1;
        while (n>1) {
            res *= n;
            --n;
        }
        return res;
    }
    
    int helper(string str) {
        unordered_map<char, int> m;
        int res = fac(str.size());
        for (char a:str) m[a]++;
        for (unordered_map<char, int>::iterator it=m.begin();it!=m.end();it++) {
            res/=fac(it->second);
        }
        cout<<str<<" : "<<res<<endl;
        return res;
    }
};