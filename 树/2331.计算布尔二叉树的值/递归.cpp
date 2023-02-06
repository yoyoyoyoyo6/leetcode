class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // 如果当前节点为叶子节点，则直接return 根节点值
        if(root->left == nullptr) {
            return root->val;
        }
        // 如果当前val为非叶子节点，且根结点值为2，代表或，则将两个孩子进行或运算
        // 递归到为叶子节点，向上运算
        if(root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        // val为非叶子节点，且根节点值为3，代表与，则递归子孩子进行与运算
        else {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};
