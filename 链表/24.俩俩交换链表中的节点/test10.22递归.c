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
    //思路时先换后面再换前面
    struct ListNode* newNode = head->next;
    //让newNode->next指向第三个元素 (假设链表长度为4)
    //进行后两个元素的交换
    head->next = swapPairs(newNode->next);
    //进行前两个元素的交换
    newNode->next = head;
    return newNode;
}
