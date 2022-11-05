//核心：将输出的栈和输入的栈之间的转换，进而在输入的栈中实现队列的操作

typedef struct {
    int* stk;
    //stk数组的长度
    int stkSize;
    //stk的容量，定义stk要开辟的大小
    int stkCapacity;
} Stack;

//输入的队列的空间开辟与输入元素
Stack* stackCreate(int cpacity) {
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

void stackPush(Stack* obj, int value) {
    obj->stk[obj->stkSize++] = value;
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    //取到栈中的元素
    return obj->stk[obj->stkSize - 1];
}

bool stackEmpty(Stack* obj) {
    //如果传进来的栈元素为空，则为真，返回true，反则返回false
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} CQueue;

CQueue* cQueueCreate() {
    CQueue* ret = malloc(sizeof(CQueue));
    //输出的栈
    ret->inStack = stackCreate(10000);
    //输入的栈
    ret->outStack = stackCreate(10000);
    return ret;
}

void in2out(CQueue* obj) {
    //传进来的栈不为空时，将obj中的一个栈从尾到头放入另外一个栈中，使得另外一个栈形成队列
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        //将输出的栈的元素个数减少相应的次数
        stackPop(obj->inStack);
    }
}

//队列尾部插入元素
void cQueueAppendTail(CQueue* obj, int value) {
    //在输出的栈中插入的元素等到输入到输入的栈时就变为了队尾的元素
    stackPush(obj->inStack, value);
}

int cQueueDeleteHead(CQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        //如果是输出的栈为空，则直接return -1
        if (stackEmpty(obj->inStack)) {
            return -1;
        }
        //如果输入的栈为空，则将输出的栈输入到输入的栈中
        in2out(obj);
    }
    //将要删除的元素存放到x中(输入的栈的头部的元素)
    int x = stackTop(obj->outStack);
    //删除
    stackPop(obj->outStack);
    //将删除了的元素return出去
    return x;
}

void cQueueFree(CQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}
