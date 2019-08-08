class Solution {
public:
    bool isPerfectSquare(int num) {
        long i=1;
        long j=num;
        while (i+1<j) {
            long mid = i+(j-i)/2;
            if (num == mid*mid) return true;
            else if (num < mid*mid) j = mid;
            else i = mid;
        }
        return i*i==num || j*j==num;
    }
};

// Newton's Method:
class Solution {
public:
    bool isPerfectSquare(int num) {
        long r = num;
        while (r*r>num) {
            r = (r+num/r)/2;
        }
        return r*r == num;
    }
};