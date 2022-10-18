//指针 pA 指向 A 链表，指针 pB 指向 B 链表，依次往后遍历
//如果 pA 到了末尾，则 pA = headB 继续遍历
//如果 pB 到了末尾，则 pB = headA 继续遍历
//比较长的链表指针指向较短链表head时，长度差就消除了
//如此，只需要将最短链表遍历两次即可找到位置

typedef struct ListNode
{
  int val;
  struct ListNode* next;
}ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB)
    {
        return NULL;
    }
    struct ListNode* n1 = headA;
    struct ListNode* n2 = headB;
    while(n1 != n2)
    {
        //找不到相交点时且n1 n2 不同时为空时，就重新从headA和headB的头遍历，找到为止
        n1 = n1 == NULL ? headA : n1->next;
        n2 = n2 == NULL ? headB : n2->next;
    }
    return n1;
}
