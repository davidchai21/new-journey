class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res(arr.size(), 0);
        int count = 0;
        for (int i=0;i<arr.size();i++) {
            if (i+count<arr.size()) {
                res[i+count]=arr[i];
                if (arr[i]==0) count++;
            } else break;
        }
        arr = res;
    }
};