// 核心为两个指针之间相差k位，所以head和node同时遍历时，在当node为空时，head当前的位置即为要返回的位置

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        while(k--) {
            node = node->next;
        }
        while(node != NULL) {
            node = node->next;
            head = head->next;
        }
        return head;
    }
};
