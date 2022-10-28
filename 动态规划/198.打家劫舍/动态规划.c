//设计状态：dp[i] 表示前i间屋子能偷到的最大金额，偷有两种情况：①i不偷，偷到的金额就为dp[i-1], ②i痛，i-1不能偷，在加上i-2的金额== dp[i-2] + nums[i](i偷盗的金额)
//        最后在两种情况中取max
//状态专业方程：dp[i] = max(dp[i-1]l, dp[i-2] + nums[i]);
//设定初始状态：dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);

int max(int a, int b){
  return a > b ? a : b;
}

int rob(int* nums, int numsSize){
  int i;
  int f[101];
  f[0] = nums[0];
  for(i = 1; i<numsSize; ++i){
    if(i == 1){
      f[1] = max(nums[0], nums[1]);
    }
    else{
      f[i] = max(f[i-1], f[i-2] + nums[i]);
    }
  }
  return f[numsSize-1];
}
