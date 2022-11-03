void backTrack(int* candidates, int numsSize,int target, int* returnSize, int** returnColumnSizes,int **returnNums,int sum,int index,int *stack,int top)
//top  stack
//stack == path
//top == path.size()
{
    if(sum > target)
    {
        return;
    }

    if(sum == target)
    {
        //returnNums和(*returnColumnSizes)数组的长度不是确定的，根据top去实时开辟
        returnNums[*returnSize] = (int *)malloc(sizeof(int) * top);
        //将stack中存放的candidates数组的内容拷贝到returnNums中
        memcpy(returnNums[*returnSize] , stack, sizeof(int) * top);
        (*returnColumnSizes)[*returnSize] = top;
        //每次进来，要返回的元素个数就加一
        *returnSize             = *returnSize + 1;    
    }
    else
    {
        int i;
        for(i = index; i <numsSize ;i++)
        {
            stack[top] = candidates[i];
            //当下一次和小于等于target时才继续进行
            if(sum + candidates[i] <= target)
                backTrack(candidates,numsSize,target,returnSize,returnColumnSizes,returnNums,sum + candidates[i],i,stack,top + 1);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    //申请2^numsSize 这么大的空间
    int** returnNums        = (int **)malloc(sizeof(int*)*(200));
    *returnColumnSizes      = (int *)malloc(sizeof(int) *(200));
    *returnSize             = 0;
    int stack[31];
    int i;
    for(i = 0; i < candidatesSize ;i++)
    {
        stack[0] = candidates[i];
        backTrack(candidates,candidatesSize,target,returnSize,returnColumnSizes,returnNums,candidates[i],i,stack,1);
    }
    return returnNums;
}
