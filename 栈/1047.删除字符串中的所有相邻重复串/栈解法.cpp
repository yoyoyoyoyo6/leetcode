class Solution {
public:
    string removeDuplicates(string s) {
        // 用字符串类型模拟栈，要注意字符插入时要尾部插入
        string result;
        for(char ch : s) {
            // 如果result为空 or 栈头部元素不等于当前遍历的字符，则将当前遍历的元素入栈
            if(result.empty() || result.back() != ch) {
                result.push_back(ch);
            }
            // 如果栈头部元素等于当前遍历的元素，则消消乐，将栈顶元素出栈
            else {
                result.pop_back();
            }
        }
        return result;
    }
};
