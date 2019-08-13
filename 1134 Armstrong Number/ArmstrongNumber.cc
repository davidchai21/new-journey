class Solution {
public:
    bool isArmstrong(int N) {
        int num = N;
        int k=0;
        while (num) {
            k++;
            num/=10;
        }
        int sum = 0;
        num = N;
        while (num) {
            sum += getNum(num%10, k);
            num/=10;
        }
        return N==sum;
    }
    
    int getNum(int n, int times) {
        int res = 1;
        for (int i=0;i<times;i++) res*=n;
        return res;
    }
};