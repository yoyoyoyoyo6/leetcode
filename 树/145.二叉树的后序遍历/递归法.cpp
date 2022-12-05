class Solution {
public:
    void postorder(TreeNode* node, vector<int>& res) {
        if(node == nullptr) {
            return;
        }
        // 后序遍历：左右根
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
