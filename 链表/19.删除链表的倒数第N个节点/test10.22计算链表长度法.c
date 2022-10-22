struct ListNode
{
  int val;
  struct ListNode* next;
}; 

//计算链表元素个数
int getLength(struct ListNode* head) {
    int length = 0;
    while (head) 
    {
        ++length;
        head = head->next;
    }
    return length;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    int length = getLength(head);
    struct ListNode* cur = dummy;
    //当cur遍历到lengh-n时，cur->next指向的内容就是要删除的元素
    for (int i = 1; i < length - n + 1; ++i) 
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    //创建一个ans变量存放dummy，再将dummy free掉，删除了元素
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}
