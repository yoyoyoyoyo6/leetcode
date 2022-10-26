int maxSubArray(int* nums, int numsSize){
    int pre = 0, maxAns = nums[0];
    for (int i = 0; i < numsSize; i++) {
        //fmax是快速对比两数大小
        //pre存放子数组和
        pre = fmax(pre + nums[i], nums[i]);
        //maxAns继续对比
        maxAns = fmax(maxAns, pre);
    }
    return maxAns;
}
