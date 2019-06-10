class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int last = -1;
        for (int i=0;i<32;i++) {
            if ((N>>i)&1) {
                if (last == -1) last = i;
                else {
                    res = max(res, i-last);
                    last = i;
                }
            }
        }
        return res;
    }
};