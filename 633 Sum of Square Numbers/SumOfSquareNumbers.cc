class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i=0;i*i<=c;i++) {
            if (binarySearch(c-i*i)) return true;
        }
        return false;
    }
    
    bool binarySearch(int n) {
        long left = 0;
        long right = n;
        while (left+1<right) {
            long mid = left + (right-left)/2;
            if (mid*mid == n) return true;
            else if (mid*mid<n) left = mid;
            else right = mid;
        }
        return left*left==n || right*right==n;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0;i*i<=c;i++) {
            double root = sqrt(c-i*i);
            if (root == (int)root) return true;
        }
        return false;
    }
};