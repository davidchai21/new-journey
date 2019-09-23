class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sum = 0;
        int i=0;
        for (;i<arr.size();i++) {
            sum += arr[i];
            if (sum>5000) break;
        }
        return i;
    }
};