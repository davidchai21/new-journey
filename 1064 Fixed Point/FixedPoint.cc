class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int left = 0;
        int right = A.size()-1;
        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (A[mid]<mid) left = mid+1;
            else if (A[mid]>mid) right = mid-1;
            else right = mid;
        }
        if (A[left]==left) return left;
        if (A[right]==right) return right;
        return -1;
    }
};