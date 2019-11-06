class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int res = (arr[0]+arr.back())*(arr.size()+1)/2;
        for (int i:arr) res-=i;
        return res;
    }
};