struct ListNode{
  int val;
  struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head){
    //用n和k代替了arr数组的功能
    int n = 0;
    struct ListNode* node = head;
    while(node != NULL)
    {
        ++n;
        node = node->next;
    }
    int k = 0;
    node = head;
    while(k<n/2)
    {
        ++k;
        node = node->next;
    }
    return node;
}
