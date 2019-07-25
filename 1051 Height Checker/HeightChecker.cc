class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> record = heights;
        int res = 0;
        sort(record.begin(), record.end(), [](int a, int b){return a<b;});
        for (int i=0;i<record.size();i++) {
            if (heights[i]!=record[i]) res++;
        }
        return res;
    }
};