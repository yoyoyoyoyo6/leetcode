class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
    string dfs(string s, int &pos) {
        // 存放要return的结果
        string ans = "";
        // 倍数
        int cnt = 0;
        while(pos < s.size()) {
            // ch存放当前遍历的字符
            char ch = s[pos];
            // 如果当前遍历的为字符，则加入ans中
            if(isalpha(ch)) {
                ans += ch;
            }
            // 如果为数字，则转为int类型，存放进cnt中
            else if(isdigit(ch)) {
                cnt = cnt * 10 + (ch - '0');
            }
            // 如果为左括号，则继续往里面递归，等于将一个大的括号分为了多个小括号之间的问题，继续递归下一个括号内的内容
            else if(ch == '[') {
                // 将pos++，跳过括号
                pos++;
                // 用sub存放递归的结果，即为内括号中的结果
                string sub = dfs(s, pos);
                // 外括号的结果和内括号的结果同时增加cnt倍
                while(cnt--) {
                    ans += sub;
                }
                // 再将倍数重置
                cnt = 0;
            }
            // 如果为右括号则说明当前的括号已经遍历完，可以直接结束此次的递归
            else if(ch == ']') {
                return ans;
            }
            // 如果都不满足，则继续向下遍历
            pos++;
        }
        // 将结果return
        return ans;
    }
};
