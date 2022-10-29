//前缀和：
//一维前缀和：有一个一维数组x和一维前缀和数组y,则
//y0 = x0  y1 = x0 + x1  y2 = x0 + x1 + x2  yn = x0 + x1 + x2 + ..... + xn
//代码实现: yn = yn-1 + xn;
/*for(int i=0;i<n;i++)
{
    if(i==0) y[i]=x[i];
    else y[i]=y[i-1]+x[i];
}*/
//二维前缀和：有一个二维数组x和一个二维前缀和数组y，则
// y0,0 = x0,0    y0,1 = x0.0 + x0.1    y1,0 = x0.0 + x1,0    y2,2 = x0.0 + x0.1 + x0.2 + x1.0 + x1.1 + x1.2 + x2.0 + x2.1 + x2.2
//代码实现: A x.y = A x-1,y + A x,y-1 - A x-1,y-1 + B x,y 
/*for(int y=0;y<n;y++)//n行
    for(int x=0;x<m;x++)//m列
    {
        if(x==0&&y==0) b[y][x]=a[y][x];//左上角的值
        else if(x==0) b[y][x]=b[y-1][x]+a[y][x];//第一列
        else if(y==0) b[y][x]=b[y][x-1]+a[y][x];//第一行
        else b[y][x]=b[y-1][x]+b[y][x-1]-b[y-1][x-1]+a[y][x];
    }
}*/


//前缀和的优势：以(o1)的时间复杂度得到某块区间的总和
//给定的区间  [left, right]
//在该区间的所有值的总和 = ret = y[right] - y[left-1];




typedef struct {
    int*sums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* ret = malloc(sizeof(NumArray));
    //将前缀和数组 sums 的长度设为 n+1 的目的是为了方便计算sumRange(i,j)，
    //不需要对 i=0 的情况特殊处理。
    ret->sums = malloc(sizeof(int) * (numsSize + 1));
    ret->sums[0] = 0;
    for(int i=0; i<numsSize; i++){
        //前缀和数组 sums
        ret->sums[i + 1] = ret->sums[i] + nums[i];
    }
    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    //用前缀和数组去求区间内元素的总和
    //因为开辟前缀和数组的空间时增加了一个空间，所以不是right 和 left-1区间，而是都加一，避免left为0时的情况
    return obj->sums[right+1] - obj->sums[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->sums);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
