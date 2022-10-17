//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。

//解题思路为快慢指针
//设置一个慢指针和一个快指针
//struct ListNode* fast = head->next;  //快
//struct ListNode* slow = head;    //慢
//如果慢的指针的指向和快的指针的指向相同，则形成了一个环形链表
//if(slow == fast)  -> return true;
//if(slow != fast)  -> return false;
//要让快链表在循环过程中跳跃的比慢链表要快->fast = fast->next->next;    slow = slow->next; 
//让快指针快速遍历链表，方便撞上慢指针

typedef struct ListNode
{
  int val;
  struct ListNode* next;
};

bool hasCycle(struct ListNode *head) {
if (head == NULL || head->next == NULL) 
    {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) 
    {
        if (fast == NULL || fast->next == NULL) 
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
