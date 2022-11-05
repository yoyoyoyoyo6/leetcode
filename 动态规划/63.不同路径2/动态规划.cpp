class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //行
        int m = obstacleGrid.size();
        //列
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //当遇到障碍物时，后面的dp数组值就只能为0，所以到obstacleGrid[][] == 1 时直接停止即可
        for(int i =0; i<m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for(int i = 1; i<m; i++){
            for(int j =1; j<n; j++){
                //当obstacleGrid[i][j] == 0 时，才能拿到当前路径的步骤数
                //当obstacleGrid[i][j] == 1 时，直接跳过
                if(!obstacleGrid[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
