class Solution {
public:
    void recursion(vector<int> &ret, ListNode*node) {
        if(!node) return;
        recursion(ret, node->next);
        ret.push_back(node->val);
    }

    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        recursion(ret, head);
        return ret;
    }
};
