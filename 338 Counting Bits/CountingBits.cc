class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        for (int i=0;i<=num;i++) res[i]=helper(i);
        return res;
    }
    
    int helper(int n) {
        int res = 0;
        while (n) {
            res++;
            n&=n-1;
        }
        return res;
    }
};

// Linear:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for (int i=1;i<=num;i++) {
            res[i]=res[i/2]+i%2;
        }
        return res;
    }
};