// 核心：单调队列的实现，将队尾始终放窗口中的最大值，保持单调性


class Solution {
private: 
    // 实现一个单调队列 
    class MyQueue {
    public:
            // 双向队列，即为队列的头和尾都可以进行pop和push的操作
            deque<int> que;
            // 该函数用于移动窗口时将最左边的元素删除
            // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
            // 同时pop之前判断队列当前是否为空。
            void pop(int value) {
                if(!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }
        // 该函数用于将元素入队，并维护队列的单调性(由大到小)
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while(!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 用于得到队列的最大值，即为最左边的元素
        int front() {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        // 用于return
        vector<int> result;
        // 将第一个窗口的元素按单调队列的方式入队
        for(int i=0; i<k; i++) {
            que.push(nums[i]);
        }
        // result存放队列左边的最大值
        result.push_back(que.front());
        
        for(int i=k; i<nums.size(); i++) {
            // 将窗口最左边的元素pop
            que.pop(nums[i - k]);
            // 将窗口最右边的元素push
            que.push(nums[i]);
            // 存放最大值
            result.push_back(que.front());
        }
        return result;
    }
};
