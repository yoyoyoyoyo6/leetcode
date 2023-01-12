class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // 创建一个哈希表，用于存放knowledge的信息，方便查找
        unordered_map<string, string> dict;
        // 将knowledge中的信息录入哈希表中
        for(auto& know : knowledge) {
            dict[know[0]] = know[1];
        }

        // addKey作为遇到括号的判断标准
        bool addKey = false;
        // key用于存放knowledge括号内的内容，用于查找
        string key, res;

        for(char c : s) {

            // 遇到左括号，则说明key要开始录入，记addkey为true
            if(c == '(') {
                addKey = true;
            }

            // 遇到右括号说明录入结束，用key进行查找
            else if(c == ')') {

                // 如果当前key在哈希表中出现过，则让res录入dict中的value
                if(dict.count(key) > 0) {
                    res += dict[key];
                }

                // 没出现过则没匹配成功，则用？代替括号内的内容
                else {
                    res.push_back('?');
                }

                // 查找结束，向下继续遍历到左括号，所以记addKey为false
                addKey = false;
                // 清楚key
                key.clear();
            }

            // 遍历到括号中的元素
            else {

                // 前面为左括号，key开始录入
                if(addKey) {
                    key.push_back(c);
                }
                
                // 反之则res录入
                else {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};
