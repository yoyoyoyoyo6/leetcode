class Solution {
public:
    string decodeMessage(string key, string message) {
        char cur = 'a';
        // 创建一个哈希表，用于将key中的信息转化与对message解码
        unordered_map<char, char> rules;
        // 将key中的信息为hashtable中的key，cur作为二十六个字母的遍历工具和hashtable中的value，
        for(char c : key) {
            // 如果当前遍历的字符不为空且没在hashtable的键中出现过，则存放入hashtable中
            if(c != ' ' && !rules.count(c)) {
                rules[c] = cur;
                ++cur;
            }
        }
        // 解码message
        // 将message中的字符作为键，用hashtable中的value直接覆盖掉message中当前遍历的元素，减少空间浪费
        for(char& c : message) {
            if(c != ' ') {
                c = rules[c];
            }
        }
        return message;
    }
};
