int cmp(const void* ptr1, const void* ptr2) {
    return *((int*)ptr1) > *((int*)ptr2);
}

int threeSumClosest(int* nums, int n, int target){
    qsort(nums, n, sizeof(int), cmp);
    int best = 1e7;
    for(int i=0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target){
                return target;
            }
            //如果sum离target的距离比best要近
            if(abs(sum - target) < abs(best - target)){
                best = sum;
            }
            //如果sum比target要大，则说明是nums[right]大过头了，让right--，但要判重
            if(sum > target){
                int right0 = right - 1;
                while(left < right0 && nums[right] == nums[right0]){
                    --right0;
                }
                right = right0;
            }
            else{
                //判重 + left++
                int left0 = left + 1;
                while(left0 < right && nums[left] == nums[left0]){
                    ++left0;
                }
                left = left0;
            }
        }
    }
    return best;
}
