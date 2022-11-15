class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stk.push(0);
        int result = 0;
        for(int i = 1; i < heights.size(); i++) {
                while(heights[i] < heights[stk.top()]) {
                    int cur = stk.top();
                    stk.pop();
                    int left = stk.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[cur];
                    result = max(result, w*h);
                }
                stk.push(i);
        }
        return result;
    }
};
