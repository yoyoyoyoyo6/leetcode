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
    //反转链表函数
    ListNode* revest(ListNode *head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }



    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;

        //找到链表的中点，用slow指针代表中间节点，因为slow指针走的步数是fast指针的一半
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //如果链表数为奇数，则让slow指针加一
        if(fast != nullptr) {
            slow = slow->next;
        }
        
        //反转slow后的链表，用后面的链表和前面的链表去对比，判断是否相同
        slow = revest(slow);
        //让fast指针继续指向头
        fast = head;

        //将slow指针作为遍历的工具，和fast指针形成一前一后
        while(slow != nullptr){
            //如果俩指针指向的数有不相等的，则直接return false
            if(fast->val != slow->val) {
                return false;
            }
            //继续向前遍历，步幅都为1个节点
            fast = fast->next;
            slow = slow->next;
        }
        //跳出循环则说明满足条件，return true
        return true;
    }
};
