class Solution {
public:
    int numTrees(int n){
        //dp[i] ： 1到i为节点组成的⼆叉搜索树的个数为dp[i]
        vector<int> dp(20);
        //初始化状态dp[0] = dp[1] = 0  0和1都为一个节点，所以都为1
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                //在1-i范围中，节点个数就等于j前的节点组成的二叉搜索数的个数乘以j后的二叉搜素树的个数，因为前后对称，j后直接取i-j元素的个数即可
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
   }
}
