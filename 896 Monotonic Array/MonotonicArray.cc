class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size()<=1) return true;
        int i=0;
        int bit = 0;
        while (i<A.size()-1) {
            if (A[i]<A[i+1]) {
                bit = 1;
                break;
            } else if (A[i]>A[i+1]) {
                bit = -1;
                break;
            }
            i++;
        }
        if (i==A.size()-1) return true;
        while (i<A.size()-1) {
            if (A[i]<A[i+1] && bit == -1 || A[i]>A[i+1] && bit == 1) return false;
            i++;
        }
        return true;
    }
};