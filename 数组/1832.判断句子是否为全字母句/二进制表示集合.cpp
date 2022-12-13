class Solution {
public:
    bool checkIfPangram(string sentence) {
        // 将26个字母转为26个二进制位
        int state = 0;
        for(auto c : sentence) {
            // 将每一个字母都转为数字后再转为二进制位输入state中，两数取或
            state |= 1 << (c - 'a');
        }
        // 是否为2^26 - 1，(0代表a)
        return state == (1 << 26) - 1;
    }
};
