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
    ListNode *frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode){
        if(currentNode != nullptr){
            if(!recursivelyCheck(currentNode->next)){
                return false;
            }
            if(currentNode->val != frontPointer->val){
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};

//递归的核心为从后往前开始执行，所以我们能将两个指针一头一尾进行遍历
//frontPointer指针指向前，currentNode指针进行递归指向后
//如果俩个指针所指向的val不相等，直接return false，反之则遍历到底为空返回true；
