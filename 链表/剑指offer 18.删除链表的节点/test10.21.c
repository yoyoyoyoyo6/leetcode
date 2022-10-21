struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* node = head->next;
    struct ListNode* n = head;
    while(node != NULL)
    {
        //防止第一个元素就是我要删除的元素
        if(head->val == val)
        {
            return head->next;
        }
        if(node->val == val)
        {
            n->next = node->next;
            free(node);
            break;
        }
        else
        {
            n = node;
            node = node->next;
        }
    }
    return head;
}
