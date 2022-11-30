class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newNode;
    }
};
