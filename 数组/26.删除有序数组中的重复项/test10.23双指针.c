//主要问题是俩指针在何种条件下才发生改变

int removeDuplicates(int* nums, int numsSize){
  if(numsSize == 0){
    return 0;
  }
  int fast = 1;
  int slow = 1;
  while(fast < numsSize){
    if(nums[fast] != nums[fast-1]){
      nums[slow] = nums[fast];
      ++slow;
    }
    ++fast;
  }
  return slow;
}
