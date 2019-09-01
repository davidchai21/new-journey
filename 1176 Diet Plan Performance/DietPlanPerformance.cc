class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n=calories.size();
        int res = 0;
        int colorie = 0;
        for (int i=0;i<k;i++) colorie += calories[i];
        if (colorie>upper) res=1;
        else if (colorie<lower) res =-1;
        for (int i=k;i<n;i++) {
            colorie-=calories[i-k];
            colorie+=calories[i];
            if (colorie>upper) res++;
            else if (colorie<lower) res--;
        }
        return res;
    }
};