struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
//先让p指针走k步；   用p代替k的位置
//然后让p指针和head指针一起前进  两个指针相差k-1位，当p==NULL时，head刚好就指向k的下一个元素
//当p走到尽头时，返回head
    struct ListNode* p = head;
    while(k--)
    {
        p = p->next;
    }
    while(p)
    {
        p = p->next;
        head = head->next;
    }
    return head;
}
