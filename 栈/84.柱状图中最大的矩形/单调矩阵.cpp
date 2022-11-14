class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 栈内元素存放的是下标
        stack<int> st;
        //防止数组元素为空，首元素插入一个0
        heights.insert(heights.begin(), 0);
        //数组尾部插入一个0
        heights.push_back(0);
        st.push(0);
        int result = 0;
        // 第一个元素已经入栈，从下标1开始
        for(int i = 1; i < heights.size(); i++) {
            // 如果栈顶元素要小于对比的元素，则该将该元素放入栈顶(是该元素的下标入栈)
            if(heights[i] > heights[st.top()]) {
                st.push(i);
            }
            // 如果对比的元素等于栈顶的元素，则重放一遍(也可以不放)
            else if(heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            }
            // 如果对比的元素要小于栈顶的元素，则将栈中的元素一直弹出，直至栈顶元素要小于对比的元素
            else {
                // 可能要有一直弹出的操作，所以使用while循环

                // i在此时是一个静态的变量，st.top()就为一个动态的变量
                // 依据在i和st.top()在该条件和while循环中的性质，就能动态的基于st.top()去看待面积的计算

                // 为什么栈st中存放下标而非元素呢？：因为要求的宽是要计算的两个元素之间的原本在数组中的下标的差值，
                //      所以遍历的工具都一直为下标
                while(heights[i] < heights[st.top()]) {
                    // 当元素出栈时，说明该元素是出栈元素向后找的第一个比其小的元素
                    // 当元素出栈时，说明新栈顶元素是出栈元素向前找的第一个比其小的元素
                    
                    // 栈顶和栈顶的下一个元素以及要入栈的三个元素组成了我们要求最大面积的高度和宽度
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = max(result, w*h);
                }
                st.push(i);
            }
        }
        return result;
    }
};

// 核心：找每个柱子左右两边第一个小于该柱子的柱子。
