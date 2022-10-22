struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = 0;
    newNode->next = head;
    //创建一个快指针
    struct ListNode* first = head;
    //一个慢指针
    struct ListNode* second = newNode;
    for(int i=0; i<n; ++i)
    {
        //让first指向要删除的元素
        first = first->next;
    }
    while(first)
    {
        //first和second始终差了n个元素，所以只要second加上这个n，就可以到要删除元素的位置
        //     而这个n正好是first == NULL时的距离
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    struct ListNode* ans = newNode->next;
    free(newNode);
    return ans;
}
