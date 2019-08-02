class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> residue(60, 0);
        for (int t:time) residue[t%60]++;
        int res = residue[30]*(residue[30]-1)/2+residue[0]*(residue[0]-1)/2;
        for (int i=1;i<30;i++) {
            res += residue[i]*residue[60-i];
        }
        return res;
    }
};