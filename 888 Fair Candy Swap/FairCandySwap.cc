class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = 0;
        for (int i=0;i<A.size();i++) sum+=A[i];
        for (int i=0;i<B.size();i++) sum-=B[i];
        sum/=2;
        unordered_set<int> s(B.begin(), B.end());
        for (int i=0;i<A.size();i++) {
            if (s.find(A[i]-sum)!=s.end()) return {A[i], A[i]-sum};
        }
        return {};
    }
};