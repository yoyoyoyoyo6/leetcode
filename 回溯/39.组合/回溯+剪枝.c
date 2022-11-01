int *path;
int pathSize;

int **ans;
int ansSize;

void backtracking(int n, int k, int strantIndex){
    if(pathSize == k){
        int *temp = malloc(sizoef(int) * k);
        int i;
        for(i=0; i<k; i++){
            temp[i] = path[i];
        }
        ans[ansSize++] = temp;
        return ;
    }
    int j;
    //剪枝的核心体现在j遍历时的上界，只遍历下一个根节点，不全部遍历，减少时间浪费
    for(j=strantIndex; j< n - (k - pathSize); j++){
        path[pathSize++] = j;
        backtracking(n, k, j + 1);
        pathSize--;
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    path = (int*)malloc(sizeof(int) * k);
    ans = (int**)malloc(sizeof(int*) * 10000);
    pathSize = ansSize = 0;
    backtracking(n, k, 1);
    *returnColumnSizes = malloc(sizoef(int) * (returnSize));
    *returnSize = ansSize;
    for(int i=0; i<*returnSize; i++){
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}
