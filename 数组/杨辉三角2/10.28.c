//要返回的是在给定rowIndex行的杨辉三角值

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//由杨辉三角1衍生来的方法
int* getRow(int rowIndex, int* returnSize){
  *returnSize = rowIndex + 1;
  int* ret[rowIndex + 1];
  for(int i=0; i<rowIndex; i++){
    ret[i] = malloc(sizeof(int) * (i + 1));
    ret[i][0] = ret[i][i];
    for(int j=1; j<i; j++){
      ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
    }
  }
  return ret[rowIndex];
}

//只创建一个数组的方法
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* row = malloc(sizeof(int) * (*returnSize));
    memset(row, 0, sizeof(int) * (*returnSize));
    row[0] = 1;
    for(int i=1; i<=rowIndex; ++i){
        for(int j = i; j>0; --j){
            row[j] += row[j-1];
        }
    }
    return row;
}
