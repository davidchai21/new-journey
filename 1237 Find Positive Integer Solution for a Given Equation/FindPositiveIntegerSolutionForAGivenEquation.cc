/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int> > res;
        for (int i=1; i<=1000; ++i) {
            int t = helper(customfunction, i, z);
            if (customfunction.f(i,t)==z) res.push_back({i,t});
        }
        return res;
    }
private:
    int helper(CustomFunction& customfunction, int x, int val) {
        int i=1;
        int j=1000;
        while (i+1<j) {
            int mid = i+(j-i)/2;
            if (customfunction.f(x,mid)==val) return mid;
            else if (customfunction.f(x,mid)<val) i=mid+1;
            else j=mid-1;
        }
        if (customfunction.f(x,j)==val) return j;
        return i;
    }
};