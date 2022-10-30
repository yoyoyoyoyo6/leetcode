//我们需要将一个左边的「较小数」与一个右边的「较大数」交换，以能够让当前排列变大，从而得到下一个排列。
//同时我们要让这个「较小数」尽量靠右，而「较大数」尽可能小。当交换完成后，「较大数」右边的数需要按照升序重新排列。这样可以在保证新排列大于原来排列的情况下，使变大的幅度尽可能小。
//核心：找出左边的较小数和右边的较大数
//较小数的查找：从数组最后一个元素开始查找一个升序区间，如果nums[i] < nums[i+1] 那么[i+1, n)为升序区间，nums[i]就为较小数
//较大数的查找：从数组最后一个元素开始查找第一个比nums[i] 大的数，定义为nums[j]
//最后将较小数和较大数进行交换，再将[i+1, n)改为升序

void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

//升序函数
void reverse(int *nums, int left, int right) {
    while (left < right) {
        swap(nums + left, nums + right);
        left++, right--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i = numsSize - 2;
    //注意等于号，如果为nums[i] > nums[i + 1]时，当数组元素相等时，
    //下面数组升序时，可能产生错误，即为本身和本身这个区间升序
    while(i >= 0 && nums[i] >= nums[i+1]){
        i--;
    }
    if(i >= 0){
        int j = numsSize - 1;
        while(j >= 0 && nums[i] >= nums[j]){
            j--;
        }
        swap(nums + i, nums + j);
    }
    //将i+1到nusmSize - 1的元素升序排列
    reverse(nums, i + 1, numsSize - 1);
}
