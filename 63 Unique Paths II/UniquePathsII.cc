class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) return 0;
        int n = obstacleGrid[0].size();
        if (!n) return 0;
        vector<long> dp(n,0);
        for (int i=0;i<n;i++) {
            if (obstacleGrid[0][i]) break;
            else dp[i]=1;
        }
        for (int i=1;i<m;i++) {
            if (obstacleGrid[i][0]) dp[0]=0;
            for (int j=1;j<n;j++) {
                if (obstacleGrid[i][j]) dp[j]=0;
                else dp[j]+=dp[j-1];
            }
        }
        return dp.back();
    }
};