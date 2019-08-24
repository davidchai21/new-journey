class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        int A=0;
        int B=0;
        for (int i=0;i<seq.size();i++) {
            if (seq[i]=='(') {
                if (A==B) {
                    A++;
                    res[i]=0;
                } else {
                    B++;
                    res[i]=1;
                }
            } else {
                if (A==B) {
                    res[i]=1;
                    B--;
                } else {
                    res[i]=0;
                    A--;
                }
            }
        }
        return res;
    }
};