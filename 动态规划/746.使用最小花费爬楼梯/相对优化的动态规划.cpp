class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]的定义：到达第i个台阶所花费的最少体⼒为dp[i]
        vector<int> dp(cost.size());
        //定义初始状态
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size(); i++){
            //dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
            //加上cost[i]是因为无论怎样走出这一步都有花费cost[i]的体力
            //当前的最小体力值可以由前两阶梯的dp数组值之中的最小值得到
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        //注意最后⼀步可以理解为不⽤花费，所以取倒数第⼀步，第⼆步的最少值(最后一步的花费直接取前两位中的min即可)
        return min(dp[cost.size()-1], dp[cost.size() - 2]);
    }
};
