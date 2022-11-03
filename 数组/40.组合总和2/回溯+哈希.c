//难点主要体现在去重的步骤上 ：利用哈希数组 也等同于C++解法中的used数组

void backTrack(int* candidates, int numsSize,int target, int* returnSize, int** returnColumnSizes,int **returnNums,int sum,int index,int *stack,int top)
{
    if(sum > target)
    {
        return;
    }

    if(sum == target)
    {
        returnNums[*returnSize] = (int *)malloc(sizeof(int) * top);
        memcpy(returnNums[*returnSize] , stack, sizeof(int) * top);
        (*returnColumnSizes)[*returnSize] = top;
        *returnSize             = *returnSize   + 1;    
    }
    else
    {
        int i;
        //用于存放元素是否出现过的哈希数组
        int hashSet[51] = {0};
        for(i = index + 1; i <numsSize ;i++)
        {
            //为0时，说明该元素前面没出现过，则对该元素进行操作
            if(hashSet[candidates[i]]  == 0)
            {
                //将该元素赋1，标记出现
                hashSet[candidates[i]]  = 1;
                stack[top] = candidates[i];
                if(sum + candidates[i] <= target)
                    backTrack(candidates,numsSize,target,returnSize,returnColumnSizes,returnNums,sum + candidates[i],i,stack,top + 1);
            }
        }
    }
}

int compareFunc(void *a,void *b)
{
    if(*(int *) a >= *(int *) b )
    {
        return 1;
    }
    return -1;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    //申请2^numsSize 这么大的空间
    int** returnNums        = (int **)malloc(sizeof(int*)*(200));
    *returnColumnSizes      = (int *)malloc(sizeof(int) *(200));
    *returnSize             = 0;
    
    //排序，将重复出现的元素放在一起
    qsort(candidates,candidatesSize,sizeof(int),compareFunc);
    int stack[31];
    int i;
    int hashSet[51] = {0};
    for(i = 0; i < candidatesSize ;i++)
    {
        if(hashSet[candidates[i]] == 0 )
        {
            hashSet[candidates[i]]  = 1;
            stack[0] = candidates[i];
            backTrack(candidates,candidatesSize,target,returnSize,returnColumnSizes,returnNums,candidates[i],i,stack,1);
        }
    }
    return returnNums;
}
