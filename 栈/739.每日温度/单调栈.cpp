class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ans(temperatures.size());
        for(int i=0; i<temperatures.size(); i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prve = stk.top();
                ans[prve] = i - prve;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

// 核心思路：单调栈+数组
// 将栈存放每个元素的下标，如果该下标所代表的元素要小于当前遍历的元素，则将该元素的下标存放入栈中(单调递增)
// 如果当前遍历元素要比栈顶元素大，则将栈顶元素出栈，
// 此时的栈顶元素是当前遍历元素的前一个元素，所以用当前遍历元素的下标减去栈顶元素的下标，得到answer[stk.top()]的元素的值
// 因为answer[stk.top()]和比它大的第一个元素相差即为当前遍历元素和栈顶元素的差值 i - stk.pop()
// 此时栈顶元素为变量，能通过遍历得到元素和比它大的第一个元素的位差
