class Solution {
public:
    string findContestMatch(int n) {
        vector<string> rec(n);
        for (int i=0;i<n;i++) rec[i]=to_string(i+1);
        while (n>1) {
            for (int i=0;i<n/2;i++) {
                rec[i] = "("+rec[i]+","+rec[n-i-1]+")";
            }
            n/=2;
        }
        return rec.front();
    }
};