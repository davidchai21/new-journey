class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int smallest = A[0];
        for (int a:A) smallest = min(a, smallest);
        return !isOdd(smallest);
    }
    
    bool isOdd(int num) {
        int odd = 0;
        while (num) {
            int d = num%10;
            if (d%2) odd++;
            num /= 10;
        }
        return odd%2;
    }
};