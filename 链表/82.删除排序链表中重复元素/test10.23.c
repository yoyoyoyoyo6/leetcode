struct ListNode
{
  int val;
  struct ListNode* next;
};

//初始未理解的点：如何将节点删除了？ cur->next = next->next->next;
//    如何继续向下遍历节点，查找是否相同? while(cur->next->val == cur->next->next->val)
struct ListNode* deleteDuplicates(struct ListNode* head){
  if(!head){
    return head;
  }
  struct ListNode *newNode = malloc(sizeof(struct ListNode));
  newNode->next = head;
  struct ListNode* cur = newNode;
  while(cur->next && cur->next->next){
    if(cur->next->val == cur->next->next->val){
      //将对比的两个节点的前节点的数据域存放在x中，用于对比
      int x = cur->next->val;
      while(cur->next && cur->next->val == x){
        //删除cur->next所指向的节点，同时继续遍历下一个节点
        cur->next = cur->next->next;
      }
    }
    else{
      cur = cur->next;
    }
  }
}
