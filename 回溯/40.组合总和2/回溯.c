int* path;
int pathTop;
int** ans;
int ansTop;
//记录ans中每一个一维数组的大小
int* length;
int cmp(const void* a1, const void* a2) {
    return *((int*)a1) - *((int*)a2);
}

void backTracking(int* candidates, int candidatesSize,  int target, int sum, int startIndex) {
    if(sum >= target) {
        //若sum等于target，复制当前path进入
        if(sum == target) {
            int* tempPath = (int*)malloc(sizeof(int) * pathTop);
            int j;
            for(j = 0; j < pathTop; j++) {
                tempPath[j] = path[j];
            }
            length[ansTop] = pathTop;
            ans[ansTop++] = tempPath;
        }
        return ;
    }

    int i;
    for(i = startIndex; i < candidatesSize; i++) {
        //对同一层树中使用过的元素跳过
        if(i > startIndex && candidates[i] == candidates[i-1])
            continue;
        path[pathTop++] = candidates[i];
        sum += candidates[i];
        backTracking(candidates, candidatesSize, target, sum, i + 1);
        //回溯
        sum -= candidates[i];
        pathTop--;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    path = (int*)malloc(sizeof(int) * 50);
    ans = (int**)malloc(sizeof(int*) * 100);
    length = (int*)malloc(sizeof(int) * 100);
    pathTop = ansTop = 0;
    //快速排序candidates，让相同元素挨到一起
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    backTracking(candidates, candidatesSize, target, 0, 0);

    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int i;
    for(i = 0; i < ansTop; i++) {
        //之前的问题出在没有实时记录每次遍历的path数组的大小
        (*returnColumnSizes)[i] = length[i];
    }
    return ans;
}
