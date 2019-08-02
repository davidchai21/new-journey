class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (1) {
            int sum = getSum(n);
            if (sum == 1) break;
            else {
                if (s.find(sum)!=s.end()) return false;
                n = sum;
                s.insert(n);
            }
        }
        return true;
    }
    
    int getSum(int n) {
        int res = 0;
        while (n) {
            int d = n%10;
            n/=10;
            res += d*d;
        }
        return res;
    }
};