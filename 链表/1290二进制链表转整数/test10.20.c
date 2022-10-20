struct ListNode
{
  int val;
  struct ListNode* next;
};


int getDecimalValue(struct ListNode* head){
    int a = 0;
    struct ListNode* node = head;
    while(node != NULL)
    {
        a = a*2 + node->val;
        node = node->next;
    }
    return a;
}
