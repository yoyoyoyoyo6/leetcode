// 核心：计算链表长度后，第n - k个链表节点就为要return的节点

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* node = head;
        while(node) {
            n++;
            node = node->next;
        }
        for(head; n>k; n--) {
            head = head->next;
        }
        return head;
    }
};
