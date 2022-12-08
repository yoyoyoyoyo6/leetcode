class Solution {
public:
    bool squareIsWhite(string coordinates) {
        // 如果此时的字符串中的字符坐标相加之和为奇数，则说明当前方块为白色，反之为黑色
        return ((coordinates[0] - 'a' + 1) + (coordinates[1] - '0')) % 2 == 1;
    }
};
