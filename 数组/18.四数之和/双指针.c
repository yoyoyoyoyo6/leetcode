int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    //开辟一块空间用于存放要返回的数组
    int **quadruplets  = malloc(sizeof(int*) * 1001);
    *returnSize = 0;
    //*returnColumnSize开辟一块空间用于后序规定要返回的数组的大小
    *returnColumnSizes = malloc(sizeof(int) * 1001);
    if(numsSize < 4){
        return quadruplets;
    }
    qsort(nums, numsSize, sizeof(int), comp);
    int length = numsSize;
    for(int i=0; i<length-3; i++){
        //排重
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        //如果排序后的四个元素的和都要比target大，则后面也无继续符合的数了，直接break
        if((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3]  > target){
            break;
        }
        //如果nums[i] 加上最后三个元素都比target小，则说明nums[i] 应该还要继续增加
        if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
            continue;
        }
        for(int j=i+1; j<length-2; j++){
            //排重
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }
             if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            //让nums[j]到足够大小
            if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            int left = j + 1;
            int right = length - 1;
            while(left < right){
                long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target){
                    int *arr = malloc(sizeof(int) * 4);
                    arr[0] = nums[i], arr[1] = nums[j], arr[2] = nums[left], arr[3] = nums[right];
                    //要返回的数组是*returnSize的四倍
                    (*returnColumnSizes)[(*returnSize)] = 4;
                    //将临时存放结果的数组赋予给quadruplets，并用*returnSize来作为下标，也同时规定了要返回元素的个数
                    quadruplets[(*returnSize)++] = arr;
                    //排重
                     while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    //排重
                     while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    return quadruplets;
}
