// 经过观察可以发现，从左下角开始，棋盘的行数和列数（均从 1 开始计数）之和如果为奇数，则为白色格子，如果和为偶数，则为黑色格子。可以根据这个结论判断格子颜色。

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a' + 1) + (coordinates[1] - '0')) % 2 == 1;
    }
};
