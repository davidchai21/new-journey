class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size()<3) return false;
        if (A[0]>=A[1]) return false;
        bool flag = false;
        for (int i=1;i<A.size();i++) {
            if (!flag) {
                if (A[i]>A[i-1]) continue;
                else if (A[i]==A[i-1]) return false;
                else flag = true;
            } else {
                if (A[i]<A[i-1]) continue;
                else return false;
            }
        }
        return flag;
    }
};