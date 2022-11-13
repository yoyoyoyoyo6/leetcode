class Solution {
public:
    bool isValid(string s) {
        //s长度为奇数，则不能俩俩配对，直接return false
        if(s.size() % 2 == 1) {
            return false;
        }
        int n = s.size();

        //
        unordered_map<char, char> pairs = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        stack<char> stk;
        for(char ch : s) {
            //如果ch所代表的元素在pairs中有配对的项，则进去和栈中元素配对
            if(pairs.count(ch)) {
                //如果栈中元素为空，或者栈顶元素(例如：'{' )不等于ch('}')所对应的哈希值('{'),则直接return false
                if(stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                //将栈顶元素出栈，进行下一个栈中元素匹配
                stk.pop();
            }
            //将ch中的元素按顺序入栈，依据栈的先入后出的性质去和哈希表中的value去匹配
            else {
                stk.push(ch);
            }
        }
        //当栈中元素为空时，则说明配对完成，否则return false，匹配不成功
        return stk.empty();
    }
};
