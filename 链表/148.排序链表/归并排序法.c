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
    ListNode* sortList(ListNode* head) {
        //链表中无元素或者只有一个元素时，return head 作为终止递归的条件
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //定义一个快指针和一个慢指针，为了找到链表的中间节点
        ListNode *fast = head;
        ListNode *slow = head;

        //brk用于分割链表
        ListNode *brk;
        //找到中间节点
        while(fast != NULL && fast->next != nullptr){
            fast = fast->next->next;
            
            if(fast == NULL || fast->next == NULL){
                brk = slow;
            }
            slow = slow->next;
        }

        //将链表分割
        brk->next = nullptr;
        //递归，将以中间节点为分界线的左右链表继续分割成更小的链表，从两个节点对比，再不断向上汇总
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(slow);

        //创建一个用于存放结果的链表,结果从小到大排序
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(head1 != nullptr || head2 != nullptr) {
            //当head1为空就放head2，当head1->val >= head2->val 就放小的head2->val
            if(head1 == nullptr || (head1 != nullptr && head2 != nullptr && head1->val >= head2->val)) {
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            }
            else {
                cur->next = head1;
                head1 = head1->next;
                cur = cur->next;
            }
        }
        //return 存放结果的哑节点
        return dummy.next;
    }
};

核心：将一个完整的链表不断分割成一个个小的链表，在小链表中排好序，再回归大链表，再大链表中排好序。最终形成分链表和排序的子问题，所以考虑使用递归
