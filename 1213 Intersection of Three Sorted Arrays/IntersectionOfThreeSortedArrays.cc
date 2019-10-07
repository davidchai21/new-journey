class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        while (p1<arr1.size() && p2<arr2.size() && p3<arr3.size()) {
            int l = max(arr1[p1], max(arr2[p2], arr3[p3]));
            while (p1<arr1.size() && arr1[p1]<l) ++p1;
            if (p1==arr1.size()) break;
            while (p2<arr2.size() && arr2[p2]<l) ++p2;
            if (p2==arr2.size()) break;
            while (p3<arr3.size() && arr3[p3]<l) ++p3;
            if (p3==arr3.size()) break;
            if (arr1[p1]==arr2[p2] && arr1[p1]==arr3[p3]) {
                res.push_back(arr1[p1++]);
                ++p2;
                ++p3;
            }
        }
        return res;
    }
};