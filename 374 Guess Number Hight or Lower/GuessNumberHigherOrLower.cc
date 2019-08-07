// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i=1;
        int j=n;
        while (i<j) {
            int mid = i+(j-i)/2;
            int ans = guess(mid);
            cout << i << " " << j << endl;
            if (ans == 0) return mid;
            else if (ans==1) i=mid+1;
            else j=mid-1;
        }
        return i;
    }
};