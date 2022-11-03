class Solution {
public:
    vector<vector<string>> result;

    void backtracking(int n, int row, vector<string>& chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }
        for(int i=0; i<n; i++){
            //设计一个函数isValid判断该行该列的元素是否满足条件
            if(isValid(row, i, chessboard, n)){
                chessboard[row][i] = 'Q';
                //一行只能存放一个皇后，所以只要该行有一个满足了条件，则直接进行下一行
                backtracking(n, row+1, chessboard);
                chessboard[row][i] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n){
        int count = 0;
        //判断一行
        for(int i=0; i<row; i++){
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
        //判断45度对角线，（i-- and j--,使得能指向左上角的元素）
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        //判断135度对角线时，j应该++使得其指向右上角的元素(j指向下一个元素，i指向上一个元素，合起来就得到了右上角的元素)，
        for(int i=row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(chessboard[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};
