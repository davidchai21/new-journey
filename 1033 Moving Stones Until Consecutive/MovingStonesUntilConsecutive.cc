class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a>b) swap(a,b);
        if (a>c) swap(a,c);
        if (c<b) swap(b,c);
        vector<int> res(2);
        if (b-a==2 || c-b==2) res[0]=1;
        else res[0]=(b-a==1?0:1)+(c-b==1?0:1);
        res[1]=c-a-2;
        return res;
    }
};