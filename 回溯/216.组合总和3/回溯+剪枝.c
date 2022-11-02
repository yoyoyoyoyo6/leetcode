int *path;
int pathSize;

int **ans;
int ansSize;

//相比组合，多出来了存放和的sum
void backtrcking(int n, int k, int sum, int strantIndex){
    //剪枝，如果当前的和比n要大，则直接不用继续进行
    if(sum > n){
        return;
    }
    if(pathSize == k){
        //满足了pathSize == k，但不满足n == sum，如果return在n == sum中，则无法终止，导致报错
        if(n == sum){
            int *temp = malloc(sizeof(int) * k);
            for(int i=0; i<k; i++){
                temp[i] = path[i];
            }
            ans[ansSize++] = temp;
        }
        return;
    }
    //已经剪枝  j <= 9 - (k - pathSize) + 1,和组合中的剪枝条件类似
    for(int j=strantIndex; j<=9-(k-pathSize)+1; j++){
        //对节点进行操作
        path[pathSize++] = j;
        sum = sum + j;
        //调用函数
        backtrcking(n, k, sum, j+1);
        //回溯
        sum = sum - j;
        pathSize--;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    path = (int*)malloc(sizeof(int) * k);
    ans = (int**)malloc(sizeof(int*) * 100);
    ansSize = pathSize = 0;
    backtrcking(n, k, 0, 1);
     *returnSize = ansSize;
    *returnColumnSizes = malloc(sizeof(int*) * ansSize);
    for(int i=0; i<ansSize; i++){
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}
