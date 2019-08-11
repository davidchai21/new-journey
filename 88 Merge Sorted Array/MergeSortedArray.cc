class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        for (;k>=0;k--) {
            if (i<0) nums1[k]=nums2[j--];
            else if (j<0) break;
            else {
                nums1[k]=max(nums1[i], nums2[j]);
                if (nums1[k]==nums2[j]) j--;
                else i--;
            }
        }
    }
};