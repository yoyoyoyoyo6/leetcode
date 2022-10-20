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
    if(head->next == NULL)
    {
        return head;
    }
    int arr[101] = {0};
    struct ListNode* node = head;
    int count = 0;
    while(node != NULL)
    {
        arr[count++] = node->val;
        node = node->next;
    }
    int num = count/2;
    struct ListNode* n = head;
    for(int i = 1; i<=num; i++)
    {
        if(i == num)
        {
            return n->next;
        }
        n = n->next;
    }
    return NULL;
}
