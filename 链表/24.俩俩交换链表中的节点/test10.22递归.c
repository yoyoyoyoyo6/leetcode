struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* newNode = head->next;
    head->next = swapPairs(newNode->next);
    newNode->next = head;
    return newNode;
}
