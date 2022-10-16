struct ListNode{
  int val;
  strcut ListNode* next;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head){
        return head;
    }
    struct ListNode* node = head;
    while(node->next){
        if(node->val == node->next->val){
            node->next = node->next->next;
        }
        else{
            node = node->next;
        }
    }
    return head;
}
