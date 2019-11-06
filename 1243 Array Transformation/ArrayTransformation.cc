class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> res = arr;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i=1;i<arr.size()-1;++i) {
                if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) {
                    --res[i];
                    flag = true;
                } else if (arr[i]<arr[i-1] && arr[i]<arr[i+1]) {
                    ++res[i];
                    flag = true;
                }
            }
            arr = res;
        }
        return res;
    }
};