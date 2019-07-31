class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res(A.size(), false);
        int sum = 0;
        for (int i=0;i<A.size();i++) {
            sum = (sum*2+A[i])%5;
            if (sum==0) res[i]=true;
        }
        return res;
    }
};