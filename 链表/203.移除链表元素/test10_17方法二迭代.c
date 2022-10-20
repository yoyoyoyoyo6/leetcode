//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

/*方法二：迭代
也可以用迭代的方法删除链表中所有节点值等于特定值的节点。

用 temp 表示当前节点。如果 temp 的下一个节点不为空且下一个节点的节点值等于给定的 val，则需要删除下一个节点。删除下一个节点可以通过以下做法实现：

temp->next=temp->next->next

如果 temp 的下一个节点的节点值不等于给定的 val，则保留下一个节点，将 temp 移动到下一个节点即可。

当 temp 的下一个节点为空时，链表遍历结束，此时所有节点值等于 val 的节点都被删除。

具体实现方面，由于链表的头节点 head 有可能需要被删除，因此创建哑节点 dummyHead，令dummyHead->next = head, 初始化tmp = dummyHead,
遍历链表进行删除操作，最后返回的dummyHead->next即为删除操作后的头节点

用新建的dummyHead这个工具人，去代表head这个链表，避免了head链表被淦(题目也提示要返回新的头节点)，
再用工具人的工具人temp去遍历dummyHead链表，找到要删除的元素，删除后返回dummyHead->next
。*/


struct ListNode
{
  int val;
  struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    //让dummyHead的next指向head;== 头插，让哑节点和head产生联系
    dummyHead->next = head;
    //让temp指针去遍历dummyHead链表
    struct ListNode* temp = dummyHead;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            //要从temp的next开始，而不是temp，因为最后要返回的是dummyHead->next;
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return dummyHead->next;
}
