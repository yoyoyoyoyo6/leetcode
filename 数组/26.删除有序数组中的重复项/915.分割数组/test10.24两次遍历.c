#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//核心：left数组中的每个元素都小于等于right中的最小值

int partitionDisjoint(int* nums, int numsSize){
    int minRight[numsSize];
    minRight[numsSize-1] = nums[numsSize-1];
    for(int i = numsSize - 2; i >= 0; i--)
    {
        //用minRight数组存放nums数组中的min
        minRight[i] = MIN(nums[i], minRight[i+1]);
    }
    //创建一个maxLeft变量，存放left数组中的max，用于和minRight对比
    int maxLeft = 0;
    for(int i = 0; i < numsSize -1; i++)
    {
        maxLeft = MAX(maxLeft, nums[i]);
        if(maxLeft <=  minRight[i+1])
        {
            //如果maxLeft比minRight小，说明nums到maxLeft这个元素时的前几个元素都满足left数组的条件，return i+1;即可
            return i + 1;
        }
    }
    //跳出第二次遍历时，说明nums数组中的元素都满足left数组的要求
    return numsSize - 1;
}
