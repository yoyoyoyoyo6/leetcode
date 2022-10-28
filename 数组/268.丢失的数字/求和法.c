int missingNumber(int* nums, int numsSize){
    int sum = numsSize;
    for(int i=0; i<numsSize; i++){
        sum += i - nums[i];
    }
    return sum;
}
