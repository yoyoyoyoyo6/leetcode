//当n>=2时，可以拆分成至少两个正整数的和，令k是可拆分出的第一个正整数，则剩下的部分是n-k，n-k可以不拆分，或者可以继续拆分成至少两个正整数的和
//n>=2 ①j(i-j)   (i-j)不能继续拆分的情况
//     ②dp[i-j]*j   i-j能继续拆分的情况
//我们不知每个数是否能继续拆分，所以要求俩种情况的max
//所以状态方程为dp[i] = max(do[i], max(dp[i-j]*j, (i-j)*j));
//初始化状态：因为dp[0] = dp[1] = 0; 所以直接从dp[2]开始初始即可，dp[2] = 1;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i =3; i <= n; i++){
            for(int j = 1; j<i-1; j++){
                dp[i] = max(dp[i], max(dp[i-j]*j, (i - j)* j));
            }
        }
        return dp[n];
    }
};
