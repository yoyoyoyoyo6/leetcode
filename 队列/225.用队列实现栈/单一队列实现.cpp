class MyStack {
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        //删除栈顶元素，等于删除队列中最后一个元素
        // 用队列的长度作为遍历的工具，当遍历到size() - 1时，说明已经到了队尾，进行删除操作
        // 那则直接将遍历工具初始化为size() - 1，当遍历工具为0时，说明找到了队尾
        // 那如何用一个队列实现呢？ ： 说白了就是头插尾，将最后一个元素顶到队头，再直接进行删除操作pop()
        int size = que.size();
        size--;
        int ret = 0;
        while(size--) {
            // 将队列头元素取出再插入队尾
            que.push(que.front());
            // 在将插入后的元素(原本在队头的元素)删除
            que.pop();
        }
        // 出循环时，则说明已经遍历到队尾了，则先将队尾元素(此时的队头)取出放入ret中(因为要return删除的值)
        // 再直接pop()即可
        ret = que.front();
        que.pop();
        return ret;
    }
    
    int top() {
        //取出栈顶元素，等于取出队列尾部元素
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};
