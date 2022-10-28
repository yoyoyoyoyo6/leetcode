int singleNumber(int* nums, int numsSize){
    int ans = nums[0];
    for(int i=1; i<numsSize; i++){
        ans = ans ^ nums[i];
    }
    return ans;
}

//本身 ^ 本身 == 0
//本身 ^ 0 == 本身

// 异或也符合交换律
// a ^ b ^ a = b ^ a ^ a = b ^ (a ^ a) = b ^ 0 = b   !!!!!
