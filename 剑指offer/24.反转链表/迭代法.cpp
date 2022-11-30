class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        // cur作为一个迭代器，将pre作为一个交换指针
        while(cur != nullptr){
            // 将cur的下一个指针指向的位置存储起来
            ListNode *temp = cur->next;
            // 让cur的next指向pre指向的位置
            cur->next = pre;
            // 让pre用cur代替，完成代换
            pre = cur;
            // 让cur向下一个指针遍历
            cur = temp;
        }
        return pre;
    }
};
