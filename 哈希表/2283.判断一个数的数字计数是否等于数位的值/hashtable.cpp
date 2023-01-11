class Solution {
public:
    bool digitCount(string num) {
        // 创建一个哈希表
        // 数据录入哈希表中
        unordered_map<int, int> hash;
        // 0到n作为key
        for(int i=0; i<num.size(); i++) {
            hash[num[i] - '0']++;
        }
        // 数位 i 在 num 中出现了 num[i]次
        // 即为hash[i] == num[i] - '0'
        for(int i=0; i<num.size(); i++) {
            if(hash[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};
