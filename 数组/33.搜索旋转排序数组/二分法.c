/*将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. */

int search(int* nums, int numsSize, int target){
     if(numsSize == 1)
    {
        if(nums[0]== target)
        {
            return 0;
        }
        return -1;
    }
    int indexLeft = 0;
    int indexRight = numsSize - 1;
    int indexMiddle;
    while(indexLeft < indexRight){
        indexMiddle = (indexRight - indexLeft) / 2 + indexLeft;
        if (target == nums[indexMiddle])
        {
            return indexMiddle;
        }
        if (target == nums[indexLeft])
        {
            return indexLeft;
        }

        if (target == nums[indexRight])
        {
            return indexRight;
        }
        //因为nums数组是旋转排序后的，将本来的全升序变为俩半升序，所以要增加一个先判断哪边的条件
       if (nums[indexLeft] < nums[indexMiddle])
        {
            //左侧是有序的递增的
            if (nums[indexLeft] < target && target < nums[indexMiddle])
            {
                //在左侧内
                indexRight = indexMiddle - 1;
            }
            else
            {
                //在右侧中
                indexLeft = indexMiddle + 1;
            }
        }
        else
        {
            //右侧是有序的递增的
            if (nums[indexMiddle] < target && target < nums[indexRight])
            {
                //在右侧内
                indexLeft = indexMiddle + 1;
            }
            else
            {
                //在左侧中
                indexRight = indexMiddle - 1;
            }
        }
    }
    return -1;
}
