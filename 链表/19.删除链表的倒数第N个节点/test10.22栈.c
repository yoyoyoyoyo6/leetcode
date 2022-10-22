struct ListNode
{
  int val;
  struct ListNode* next;
};

struct Stack
{
  struct ListNode* val;
  struct Stack* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //创建一个哑节点newNode用于返回
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = 0;
    newNode->next = head;
    //创建一个栈
    struct Stack* stk = NULL;
    struct ListNode* cur = newNode;
    while(cur)
    {
        //把cur的数据域的内容存放到tmp和skt中
        struct Stack* tmp = malloc(sizeof(struct Stack));
        tmp->val = cur;
        tmp->next = stk;
        stk = tmp;
        cur = cur->next;
    }
    for(int i = 0; i<n; ++i)
    {
        //当i遍历到n-1时，stk指向的元素就是要删除的元素
        //栈的特点是先入后出
        struct Stack* tmp = stk->next;
        free(stk);
        stk = tmp;
    }
    //将prev中的==stk->val 的元素删除??????
    struct ListNode* prev = stk->val;
    prev->next = prev->next->next;
    struct ListNode* ans = newNode->next;
    free(newNode);
    return ans;
}
