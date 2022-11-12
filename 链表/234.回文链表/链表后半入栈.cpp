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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast)
        {
            if (fast->next == nullptr)
                break;
            if (fast->next->next == nullptr)
                break;

            slow = slow->next;
            fast = fast->next->next;
        }
        // 拿到链表中间位置，将其后半部分入栈
        stack<int> s;
        ListNode* cur = slow->next; // 链表长度为偶数时，slow位于上一个中间节点，我们从下一个开始
        while (cur)
        {
            s.push(cur->val);
            cur = cur->next;
        }

        // 比较栈元素和链表元素是否相等
        while (!s.empty())
        {
            if (s.top() != head->val)
                return false;
            s.pop();
            head = head->next;
        }
        return true;
    
    }
};
