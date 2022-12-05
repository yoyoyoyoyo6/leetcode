class MyQueue {
private:
    stack<int> stkout;
    stack<int> stkin;

    void inout2() {
        while(!stkin.empty()) {
            stkout.push(stkin.top());
            stkin.pop();
        }
    }
public:
    MyQueue() {

    }
    
    void push(int x) {
        stkin.push(x);
    }
    
    int pop() {
        if(stkout.empty()) {
            inout2();
        }
        int val = stkout.top();
        stkout.pop();
        return val;
    }
    
    int peek() {
        if(stkout.empty()) {
            inout2();
        }
        return stkout.top();
    }
    
    bool empty() {
        return stkin.empty() && stkout.empty();
    }
};
