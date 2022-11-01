//难点：如何判断3x3的格子

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    //哈希+二维数组
    int row[9][9] = {0};//行
    int columns[9][9] = {0};//列
    int boxes[9][9] = {0};//3x3
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                //跳过
                continue;
            }
            //形成下标 0 - 8
            char num = board[i][j] - '1';
            //三个判断条件 ①行的元素不能出现超过一次  ②列的元素不能出现超过一次 ③3x3的格子中1-9不能出现超过1次
            if(++row[i][num] > 1 || ++columns[j][num] > 1 || ++boxes[i/3*3 + j/3][num] > 1){
                return false;
            }
        }
    }
    return true;
}
