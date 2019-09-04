class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for (int i=A.size()-1;i>0;i--) {
            int index = 0;
            for (int j=1;j<=i;j++) {
                if (A[j]>A[index]) index =j;
            }
            if (index == i) continue;
            res.push_back(index+1);
            res.push_back(i+1);
            reverse(A.begin(), A.begin()+index+1);
            reverse(A.begin(), A.begin()+i+1);
        }
        return res;
    }
};