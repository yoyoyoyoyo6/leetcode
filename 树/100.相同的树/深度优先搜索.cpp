class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            // 如果左右子树同时为空，则说明遍历到底了，return true
            // 为什么return true呢？因为只有在前面元素都相等的情况下，才能满足同时遍历到空
            return true;
        }
        // 如果只有一个遍历到空，则说明不满足对称，结构不相同，则return false
        else if(p == nullptr || q == nullptr) {
            return false;
        }
        // 树的val不相等时，return false
        else if(p->val != q->val) {
            return false;
        }
        // 继续遍历左右子树，只有当左右子树同时return true才能return true
        // 此时也说明两树在结构和每个节点的值的相同
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
