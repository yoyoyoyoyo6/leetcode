class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
        min_stk.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
        
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        int val = stk.top();
        return val;
    }
    
    int getMin() {
        return min_stk.top();
    }
};
