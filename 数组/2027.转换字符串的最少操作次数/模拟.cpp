class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'X') {
                count += 1;
                // 选出的是三个连续字符，所以满足条件时直接跳过当前三个字符即可
                i += 2;
            }
        }
        return count;
    }
};
