class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //核心：尽量让⽯头分成重量相同的两堆，相撞之后剩下的⽯头最⼩ ->转换为01背包 or 分割等和子集
        vector<int> dp(15001, 0);
        int sum = 0;
        for(int i=0; i<stones.size(); i++){
            sum += stones[i];
        }
        int target = sum / 2;
        //相对分割等和子集 少了是否能平方的判断

        for(int i=0; i<stones.size(); i++){
            for(int j=target; j>=stones[i]; j--){
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        //target = sum / 2 是向下取整的，导致 sum - dp[target] 肯定要大于dp[target]，所以(sum - dp[target]) - dp[target] 剩下来的部分就是要的结果
        return sum - dp[target] - dp[target];
    }
};
