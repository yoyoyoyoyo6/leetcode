//创建一个一维数组
int *path;
int pathTop;

//创建一个二维数组
int **ans;
int ansTop;

void backtracking(int n, int k, int startIndex){
    //当path中元素个数为k个时，我们需要将path数组放入ans二维数组中
    if(pathTop == k){
        int *temp = (int*)malloc(sizeof(int) * k);
        int i;
        for(i=0; i<k; i++){
            temp[i] = path[i];
        }
        ans[ansTop++] = temp;
        return ;
    }

    int j;
    for(j = startIndex; j<=n; j++){
        //将当前节点放入path数组中
        path[pathTop++] = j;
        //进行递归
        backtracking(n, k, j + 1);
        //进行回溯，将数组最上层节点弹出，将pathTop的长度改为1，能插入下一个元素但长度不超过2
        pathTop--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    //path数组存储符合条件的结果
    path = (int*)malloc(sizeof(int) * k);
    //ans二维数组存放符合条件的结果数组的集合(数组要足够大，避免极端情况)
    ans = (int**)malloc(sizeof(int*) * 10000);
    pathTop = ansTop = 0;

    //调用函数得到相应组合，回溯算法
    backtracking(n, k, 1);
    //返回的元素个数为ans数组的元素个数
    *returnSize = ansTop;
    //returnColumnSize数组存放ans二维数组对应下标中一维数组的长度(都为k)
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int i;
    for(i = 0; i<*returnSize; i++){
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}
