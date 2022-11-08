//从01背包问题的只要sum(weight[i]) <= j  变为了只要sum(nums[i]) == j;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //存放数组元素总和
        int sum = 0;
        //dp数组的含义为：从[1-i]的范围中选取若干个数，其的总和
        vector<int> dp(10001, 0);
        //求和
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        //如果sum不能被整除，那就说明无法将数组平分为两部分，直接return false即可
        if(sum % 2 == 1) return false;
        //target存放sum的一半，作为容量j
        int target = sum / 2;
        //遍历数组中的每一个元素
        for(int i=0; i<nums.size(); i++){
            //遍历[nums[i] -- target]范围的和，取max
            for(int j=target; j>=nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
            }
        }
        //如果最大值刚好为数组的一半，则说明数组可以被平分为两部分，return true即可
        if(dp[target] == target) return true;
        //反正不满足，return false
        return false;
    }
};
