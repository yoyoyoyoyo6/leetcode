/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    //将生成的杨辉三角数组存放到ret中
    int** ret = malloc(sizeof(int*) * numRows);
    //要输出多少个行
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for(int i=0; i<numRows; ++i){
        //让ret[i]能存放i+1个元素(主要是因为i从0开始遍历)
        ret[i] = malloc(sizeof(int) * (i + 1));
        //要返回的一维数组的长度有多长
        (*returnColumnSizes)[i] = i + 1;
        //让行的头和尾都为0
        ret[i][0] = ret[i][i] = 1;
        for(int j = 1; j < i; ++j){
            //第i行的j元素是上一行左右元素的和，即为ret[i-1][j] + ret[i-1][j-1];
            ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
        }
    }
    return ret;
}
