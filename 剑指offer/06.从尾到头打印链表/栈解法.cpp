class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        //用来存放return的内容
        vector<int> ans;
        //创建一个栈
        stack<int> ret;
        ListNode* node = head;
        while(node != NULL){
            //将链表中的内容入栈
            ret.push(node->val);
            node = node->next;
        }
        while(!ret.empty()){
           //top()是取栈顶元素，不会删除里面的元素，返回栈顶的引用；
           //pop()是删除栈顶元素，返回void。
           //将栈中的内容取出放到ans数组中，再将栈中的元素删除
           ans.push_back(ret.top());
           ret.pop();
        }
        return ans;
    }
};
