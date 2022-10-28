/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    //创建一个ret空间用于存放要返回的结果
    char** ret = malloc(sizeof(char*) * numsSize);
    //将*returnSize初始化为0，方便在ret中动态的分配要输出的数字个数
    *returnSize = 0;
    int i = 0;
    while (i < numsSize) {
        int low = i;
        //让i++，用于区分是否进入过下一个while循环过，没有就直接和int high = i - 1抵消，如果进了，则high会比low大1
        i++;
        //判断后一个元素是否为前一个元素加一，是则形成一个区间，让i++并赋予给higt，否则直接返回nums[low]
        while (i < numsSize && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        int high = i - 1;
        //开辟一块空间用于存放返回的结果
        char* temp = malloc(sizeof(char) * 25);
        //将nums[low]的值输入到temp中
        sprintf(temp, "%d", nums[low]);
        //如果满足后一个元素是前一个元素加一
        if (low < high) {
            //扩大temp的范围，并将"->"输入到temp中，temp中就有了 nums[low] + "->"
            sprintf(temp + strlen(temp), "->");
            //将nums[high]输入到temp中，temp中就有了nums[low] + "->" + nums[high],形成一个区间
            sprintf(temp + strlen(temp), "%d", nums[high]);
        }
        //ret中存放temp中形成的结果，temp不是数组，无法直接返回
        ret[(*returnSize)++] = temp;
    }
    return ret;
}
