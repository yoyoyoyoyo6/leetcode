struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head){
    if(!head)
    {
        return NULL;
    }
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    //当快指针指向为空时，慢指针刚好指向中间节点
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
