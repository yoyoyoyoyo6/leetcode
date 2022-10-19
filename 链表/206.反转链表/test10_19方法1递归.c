struct ListNode
{
  int val;
  struct ListNode* next;
};


//步骤：拆分为头节点和头节点以外的节点进行交换
//head->next->next = head;    
//head->next = NULL;
//  2  3     解释：将3后的元素指向2，再将2的next指针指向为空，为尾(可以理解为将每次替换都为两个该步骤的替换)

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        //下一个元素为空或该元素为空，则不用交换
        return head;
    }
    //将新节点放进newNode中，用于返回
    struct ListNode* newNode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}
