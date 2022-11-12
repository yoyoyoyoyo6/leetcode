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
        ListNode *newNode = new ListNode(0, head);
        stack<ListNode*> stack1;
        ListNode *node = newNode;
        while(node){
            stack1.push(node);
            node = node->next;
        }
        for(int i=0; i<n; i++){
            stack1.pop();
        }
        //让pre指向栈顶的元素，用链表理解就是为要删除的元素的前一个元素
        ListNode *pre = stack1.top();
        //将该节点的下一个节点删除
        pre->next = pre->next->next;
        ListNode *ans = newNode->next;
        return ans;
    }
};

核心：在栈中是先入后出，所以将链表中的元素放入栈中时，链表中的元素的次序也就变为了顺序而非逆序，可以通过n直接找到要删除的元素
