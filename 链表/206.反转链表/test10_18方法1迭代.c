struct ListNode
{
  int val;
  struct ListNode* next;
};


struct ListNode* reverseList(struct ListNode* head){
    if(!head)
    {
        return NULL;
    }
    //创建一个存放反转链表的链表
    struct ListNode* n = NULL;
    struct ListNode* node = head;
    while(node)
    {
        //在该处node->next的值被改变，所以前提要有一个变量去存放初始的node->next的值，最后再赋予给node，以达成自增，继续遍历
        struct ListNode* cur = node->next;
        //将node的节点插入到n中，头插法
        node->next = n;
        n = node;
        node = cur;
    }
    return n;
}
