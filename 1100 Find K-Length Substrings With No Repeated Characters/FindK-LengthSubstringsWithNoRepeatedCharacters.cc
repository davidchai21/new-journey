class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (K>S.size()) return 0;
        vector<int> record(26,0);
        int oversize = 0;
        int res = 0;
        for (int i=0;i<K;i++) {
            record[S[i]-'a']++;
            if (record[S[i]-'a']==2) oversize++;
        }
        if (oversize==0) res++;
        for (int i=K;i<S.size();i++) {
            record[S[i-K]-'a']--;
            if (record[S[i-K]-'a']==1) oversize--;
            record[S[i]-'a']++;
            if (record[S[i]-'a']==2) oversize++;
            if (oversize==0) res++;
        }
        return res;
    }
};