int cmp(int* a,int* b){
    if(*a>*b)
        return 1;
    if(*a==*b)
        return 0;
    else
        return -1;
}

int thirdMax(int* nums, int numsSize){
    if(numsSize<=2){
        //元素个数小于等于2时，直接返回第一个元素即可
        return nums[numsSize-1];
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    //存放不相同的元素的个数
    int count=0;
    //排序后小在前，大在后，从后往前遍历，要取的是不相等的第三个元素
    for(int i=numsSize-1;i>0;i--){
        //前后元素不相等，count++
        if(nums[i]!=nums[i-1]){ 
             count++;
        }
        //到第三个不相等的元素时，直接return
         if(count==3){
             return nums[i];
        }
    }
    //如果从后遍历完后，nums中只有两个不相等的元素，直接return第一个元素即可
    if(count==2){
        return nums[0];
    }
    //最后一种情况，nums中只有一个元素，直接return则可
    return nums[numsSize-1];
}
