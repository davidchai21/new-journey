class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int left = 0;
        int right = A.size()-1;
        int index = right;
        while (left <= right) {
            if (abs(A[left])>abs(A[right])) {
                res[index--] = A[left]*A[left];
                left++;
            } else {
                res[index--] = A[right]*A[right];
                right--;
            }
        }
        return res;
    }
};