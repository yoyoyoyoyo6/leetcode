/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head;
        ListNode *second = dummy;
        //和second指针相差n个位，意味着当fast指针遍历到空时，second指针所指的位置就是要删除元素的位置
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        //让second指针的fast指针错位，让second指针指向要删除的元素
        while(fast != nullptr){
            fast = fast->next;
            second = second->next;
        }
        //删除元素
        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
