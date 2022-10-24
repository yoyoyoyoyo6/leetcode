//核心：逆序digits数组，不为9就+1，然后其余为9的数都改为0；
//如果digits数组都为9，则让数组扩容1个int，让扩容后的数组第一个元素为1，其余为0

int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize - 1; i >= 0; --i)
    {
        if(digits[i] != 9)
        {
            //不为9的数++
            ++digits[i];
            for(int j = i+1; j < digitsSize; ++j)
            {
                //为9的数赋0
                digits[j] = 0;
            }
            //输出多少个元素
            *returnSize = digitsSize;
            return digits;
        }
    }
    //扩容一个int
    digits = malloc(digitsSize * sizeof(int) + sizeof(int));
    for(int i = 1; i <= digitsSize; i++)
    {   
        //第一个元素赋1，其余为0
        digits[0] = 1;
        digits[i] = 0;
    }
    //输出元素加一
    *returnSize = digitsSize + 1;
    return digits;
}
