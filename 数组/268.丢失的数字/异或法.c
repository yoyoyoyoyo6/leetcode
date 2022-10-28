int missingNumber(int* nums, int numsSize){
    int i = 0;
    int ret = numsSize;
    for(i = 0; i<numsSize; i++){
        ret ^= nums[i] ^ i;
    }
    return ret;
}
