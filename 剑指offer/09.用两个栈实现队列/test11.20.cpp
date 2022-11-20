class CQueue {
private:
    stack<int> inStack, outStack;

    void in2out(){
        while(!inStack.empty()){
            //top是取出栈顶元素
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    
    CQueue() {

    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        if(outStack.empty()){
            if(inStack.empty()){
                return -1;
            }
            in2out();
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }
};
