class Solution {
public:
    string decodeString(string s) {
        // 临时存放s中的字符
        string res = "";
        // 用int类型的栈存放数字
        stack <int> nums;
        // string类型的栈存放字符
        stack <string> strs;
        // 临时存放s中的数字
        int num = 0;
        int len = s.size();
        for(int i = 0; i < len; ++ i)
        {
            // 如果s[i]为数字，则存放入nums中
            // 遇到1位以上的数字需要把前一个数字*10 ，
            // 再加上当前的数字，比如遇到12这个数字，需要进行1 * 10 + 2才能得到12
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
            }
            // 如果s[i]为字符，则加入res中
            else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
            {
                res = res + s[i];
            }
            // 如果遇到左括号，则将之前遍历的数字存入数字栈中，字符存入字符栈中
            else if(s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                nums.push(num);
                // 数字存入数字栈中，然后再重置，继续遍历
                num = 0;
                strs.push(res); 
                // 将字符存入字符栈中，然后重置，继续遍历
                res = "";
            }
            // 遇到右括号，则将栈顶的元素pop
            else //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
            {
                // times存放要重复多少次，即为s中的数字
                int times = nums.top();
                // 再将当前存放入times中的数字栈中的元素pop掉
                nums.pop();
                // 将字符栈中的元素取出来去增加tims倍，res中存放着未遇到"["存入栈中的s中的字符
                for(int j = 0; j < times; ++ j)
                    strs.top() += res;
                res = strs.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                                  //若是左括号，res会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return res;
    }
};
