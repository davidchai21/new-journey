class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i=left;i<=right;i++) {
            if (judge(i)) res.push_back(i);
        }
        return res;
    }
    
    bool judge(int n) {
        for (int i=1;i<=n;i*=10) {
            int r = (n/i)%10;
            if (r==0 || n%r) return false;
        }
        return true;
    }
};