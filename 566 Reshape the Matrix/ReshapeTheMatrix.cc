class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r*c != nums.size()*nums[0].size()) return nums;
        vector<vector<int> > res(r, vector<int>(c));
        int x=0;
        int y=0;
        for (int i=0;i<nums.size();i++) {
            for (int j=0;j<nums[0].size();j++) {
                res[x][y++]=nums[i][j];
                if (y==c) {
                    x++;
                    y=0;
                }
            }
        }
        return res;
    }
};