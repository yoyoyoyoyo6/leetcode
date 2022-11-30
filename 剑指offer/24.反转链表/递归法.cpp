// 能使用递归的原因是能将交换链表这个大问题转换为交换两个节点的小问题
// 所以着重实现对两个节点的交换操作即可
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        // 让newNode通过迭代得到链表最后一个节点
        ListNode *newNode = reverseList(head->next);
        
        // 让当前节点的下一个节点的指针指向当前节点
        head->next->next = head;
        // 让当前指针指向空
        head->next = NULL;
        return newNode;
    }
};
