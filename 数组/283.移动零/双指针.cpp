void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

//核心：让nums[right]代表的不为0的数和nums[left]指向的为0的数交换
//  如果nums[right] and nums[left] 持续!= 0, swap执行和没执行一样

void moveZeroes(int* nums, int numsSize){
  int left = 0, right = 0;
  while(right < numsSize){
    if(nums[right]){
      swap(nums + left, nums + right);
      left++;
    }
    right++;
  }
}
