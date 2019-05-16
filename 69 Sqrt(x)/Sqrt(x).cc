class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        int left = 0;
        int right = x;
        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (mid == x/mid) return mid;
            else if (mid < x/mid) left = mid;
            else right = mid-1;
        }
        if (right<=x/right) return right;
        return left;
    }
};