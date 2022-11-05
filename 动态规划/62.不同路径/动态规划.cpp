class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //定义初始状态
        //到达第一行和第一列的路径只有1种
        for(int i = 0; i<m; i++)  dp[i][0] = 1;
        for(int j = 0; j<n; j++)  dp[0][j] = 1;
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                //定义状态函数
                //dp[i][j]的路径能由左边(dp[i-1][j])和上边(dp[i][j-1])的路径和得到
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
