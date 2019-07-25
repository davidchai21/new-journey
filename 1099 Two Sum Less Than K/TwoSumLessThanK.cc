class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        if (A.size()<2 || A[0]+A[1]>=K) return -1;
        int res = A[0]+A[1];
        for (int i=0;i<A.size()-1;i++) {
            int index = binarySearch(A, K-A[i], i);
            if (index!=-1) res = max(res, A[i]+A[index]);
            else break;
        }
        return res;
    }
    
    int binarySearch(vector<int>& A, int target, int start) {
        int left = start+1;
        int right = A.size()-1;
        while (left+1<right) {
            int mid = left+(right-left)/2;
            if (A[mid]>=target) right = mid-1;
            else left = mid;
        }
        if (A[right]<target) return right;
        if (A[left]<target) return left;
        return -1;
    }
};