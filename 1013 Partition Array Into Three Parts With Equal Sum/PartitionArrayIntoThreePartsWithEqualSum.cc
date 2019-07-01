class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int average = 0;
        for (int a:A) average += a;
        if (average%3) return false;
        average/=3;
        int i = 0;
        int sum = 0;
        bool flag = false;
        while (i<A.size()) {
            sum += A[i++];
            if (sum == average) {
                if (!flag) {
                    flag = true;
                    sum = 0;
                } else return true;
            }
        }
        return false;
    }
};