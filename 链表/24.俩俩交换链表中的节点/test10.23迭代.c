struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->next = head;
    //temp后的两个元素是要交换的两个元素，作为遍历的标准与条件
    struct ListNode* temp = newNode;
    //temp后面没有节点或者后面只有一个节点时不用交换
    while(temp->next != NULL && temp->next->next != NULL)
    {
        //创建node1和node2代表要交换的两个元素
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        //让node1与node2交换位置
        node1->next = node2->next;
        node2->next = node1;
        //temp继续向前遍历，指向下一个要交换的两个元素
        temp->next = node2;
        temp = node1;
    }
    return newNode->next;
}
