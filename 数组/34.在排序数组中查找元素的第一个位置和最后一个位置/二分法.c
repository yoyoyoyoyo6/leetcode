//如果lower 为 true，则查找第一个大于等于 target 的下标，否则查找第一个大于 target 的下标。
//作用是用来得到目标元素的上界
int binarySearch(int* nums, int numsSize, int target, bool lower) {
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right) {
        int mid = (left + right) / 2;
        //当lower为真时，就能得到nums[mid] >= target 的条件进去判断,所以也能得到第一个大于等于target的下标
        //lower可以当做是否为备胎的判断标准
        if (nums[mid] > target || (lower && nums[mid] >= target)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int leftIdx = binarySearch(nums, numsSize, target, true);
    //传参false，找出第一个大于target的下标，再 - 1得出范围的上界
    int rightIdx = binarySearch(nums, numsSize, target, false) - 1;
    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (leftIdx <= rightIdx && rightIdx < numsSize && nums[leftIdx] == target && nums[rightIdx] == target) {
        ret[0] = leftIdx, ret[1] = rightIdx;
        return ret;
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}
