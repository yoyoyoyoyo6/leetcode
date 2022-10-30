/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 //qsort辅助cmp函数
int cmp(const void* ptr1, const void* ptr2) {
    return *((int*)ptr1) > *((int*)ptr2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    //开辟ans数组空间
    int **ans = (int**)malloc(sizeof(int*) * 18000);
    int ansTop = 0;
    //若传入nums数组大小小于3，则需要返回数组大小为0
    if(numsSize < 3) {
        *returnSize = 0;
        return ans;
    }
    //对nums数组进行排序
    qsort(nums, numsSize, sizeof(int), cmp);
    

    int i;
    //用for循环遍历数组，结束条件为i < numsSize - 2(因为要预留左右指针的位置)
    //最后两个元素是给left和right保留的，i最大也只能在left后，
    //left最大只能在right后，right最大只能为numsSize-1，所以i最大只能为numsSize - 3
    for(i = 0; i < numsSize - 2; i++) {
        //若当前i指向元素>0，则代表left和right以及i的和大于0。直接break
        ////因为是排序后的数组，所以只要nums[i]开始大于0时，后面就没有满足题意的left和right了
        if(nums[i] > 0)
            break;
        //去重：i > 0 && nums[i] == nums[i-1]
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        //定义左指针和右指针
        int left = i + 1;
        int right = numsSize - 1;
        //当右指针比左指针大时进行循环
        while(right > left) {
            //求出三数之和
            int sum = nums[right] + nums[left] + nums[i];
            //若和小于0，则左指针+1（因为左指针右边的数比当前所指元素大）
            if(sum < 0)
                left++;
            //若和大于0，则将右指针-1
            else if(sum > 0)
                right--;
            //若和等于0
            else {
                //开辟一个大小为3的数组空间，存入nums[i], nums[left]和nums[right]
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[2] = nums[right];
                //将开辟数组存入ans中
                ans[ansTop++] = arr;
                //去重
                while(right > left && nums[right] == nums[right - 1])
                    right--;
                while(left < right && nums[left] == nums[left + 1])
                    left++;
                //更新左右指针
                left++;
                right--;
            }
        }
    }

    //设定返回的数组大小
    *returnSize = ansTop;
    //*returnColumnSizes要开辟三倍ansTops的空间
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int z;
    for(z = 0; z < ansTop; z++) {
        (*returnColumnSizes)[z] = 3;
    }
    return ans;
}
