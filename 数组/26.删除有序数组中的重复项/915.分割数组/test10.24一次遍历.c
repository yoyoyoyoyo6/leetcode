#define MAX(a, b) ((a) > (b) ? (a) : (b))

int partitionDisjoint(int* nums, int numsSize){
    //存放left数组中的最大值
    int maxLeft = nums[0];
    //存放nums[i]的max，用于遍历与对比
    int curmax = nums[0];
    //在理想状态下，0--leftPos的范围为left数组的范围，leftPos--numsSize-1为right的范围
    //如果存在i > leftPos  且nums[i] < maxleft 那么nums[i]为非法的
    int leftPos = 0;
    for(int i = 1; i < numsSize - 1; i++)
    {
        curmax = MAX(curmax, nums[i]);
        if(nums[i] < maxLeft)
        {
            //产生非法的nums[i]时，就将maxLeft赋值为curmax
            //将leftPos的区间改为i
            leftPos = i;
            maxLeft = curmax;
        }
    }
    return leftPos + 1;
}
