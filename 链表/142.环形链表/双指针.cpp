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
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                //从头节点出发的指针
                ListNode *index1 = head;
                //从相遇点出发的指针
                ListNode *index2 = slow;
                //如果俩指针未相遇时，则继续向前遍历
                //每次遍历只能走一个节点
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                //return 环形入口节点
                return index2;
            }
        }
        //没有就return NULL
        return NULL;
    }
};

/*核心：
判断链表是否有环
如果有环，找到环的入口

推导步骤：
设从头节点到环形入口节点的距离为x，环形入口节点到fast和slow指针相遇的节点的距离为y，从相遇节点到环形入口节点的距离为z
slow指针走的距离为 x + y 
fast指针走的距离为 x + y + n * (y + z)  n为fast指针在环内走了几圈才遇到slow指针
因为fast走的步幅为2，slow走的步幅为1
所以fast指针走的距离是slow的两倍 即为  (x + y) * 2 = x + y + n * (y + n)
推导一下 得到  x = (n - 1) * (y + z) + z
令n = 1理解一下，得到x == z
意味着 从头节点出发的一个指针(index1)，从相遇点出发的一个指针(index2)，这两个指针每一次走一个节点，那当这两个指针相遇的时候就是环形入口的节点*/
