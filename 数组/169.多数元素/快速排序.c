int cmp(int* a, int* b)
{
    return *a - *b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    return nums[(numsSize - 1) / 2];
}
