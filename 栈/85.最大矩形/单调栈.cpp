class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int ans = 0;
        // 创建一个一维数组存放二维数组matrix中的信息
        vector<int> line(matrix[0].size() + 2, 0);
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                // 用line存放每列的高度，matrix[i][j]为'1'时，就用之前的高度再加一
                line[j+1] = (matrix[i][j] == '0') ? 0 : line[j+1] + 1;
            }
            // 用ans存放要return的信息
            // 将存放的每一列高度都调用函数往单调栈中判断，求得最大的矩形面积
            ans = max(ans, largestRectangleArea(line));
        }
        return ans;
    }

    // 用单调栈求最大矩形的面积，和84题柱状图中最大的矩形解法相似
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        // 相对于84题少了下列两行在数组头尾插入0的操作，
        // 是因为在初始化height数组时，就将该数组前后都增加了一列
        /*
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        */
        // 用数组模拟一个栈，直接创建一个栈也OK
        vector<int> st;
        // 用单调栈求最大矩形面积
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[i] < heights[st.back()]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
