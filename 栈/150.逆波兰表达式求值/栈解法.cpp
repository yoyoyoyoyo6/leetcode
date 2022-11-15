class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(tokens[i] == "+") stk.push(num1 + num2);
                if(tokens[i] == "-") stk.push(num2 - num1);
                // 乘法要进行类型转换，不然负数相乘或数据过大可能导致整形溢出
                if(tokens[i] == "*") stk.push((unsigned)num2 * (unsigned)num1);
                if(tokens[i] == "/") stk.push(num2 / num1);
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }
        int rueslt = stk.top();
        stk.pop();
        return rueslt;
    }
};
