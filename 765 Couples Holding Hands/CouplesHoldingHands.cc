class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        unordered_map<int,int> m;
        for (int i=0;i<row.size();i++) {
            m[row[i]] = i;
        }
        int index = 0;
        while (index < row.size()) {
            if (row[index]%2) { // odd
                if (row[index+1]!=row[index]-1) {
                    int t = m[row[index]-1];
                    swap(row[index+1], row[t]);
                    m[row[t]] = t;
                    res++;
                }
            } else {    // even
                if (row[index+1]!=row[index]+1) {
                    int t = m[row[index]+1];
                    swap(row[index+1], row[t]);
                    m[row[t]] = t;
                    res++;
                }
            }
            index+=2;
        }
        return res;
    }
};