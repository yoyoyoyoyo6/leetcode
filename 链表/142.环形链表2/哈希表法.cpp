/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //创建一个哈希表visited
        unordered_set<ListNode*> visited;
        //用head作为遍历工具
        while(head != nullptr) {
            //如果重复出现过(即为count函数返回的不是0)，则直接return此时的节点即可
            if(visited.count(head)) {
                return head;
            }
            //反正则将当前节点存放在哈希表中
            visited.insert(head);
            //继续向后遍历
            head = head->next;
        }
        return nullptr;
    }
};
