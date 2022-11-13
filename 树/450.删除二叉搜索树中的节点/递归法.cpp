/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //root为空，代表未搜索到key的节点，return 空
        if(root == nullptr) {
            return nullptr;
        }
        //key的值小于根节点的值，说明key可能在根节点的左子树中
        //需要递归的在root->left调用deleteNode
        //return root的目的是找到要删除的节点可以return出来
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        //key的值大于根节点的值，说明key可能在根节点的右子树中
        //需要递归的在root->right调用deleteNode
        //return root的目的是找到要删除的节点可以return出来
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        //如果root->val == key，则说明找到了要删除的节点，此时进行删除的操作
        if(root->val == key) {
            //如果要删除节点的左右子树都为空，则直接删除，return nullptr即可
            if(!root->left && !root->right) {
                return nullptr;
            }
            //如果左子树为空，则用右子树的值代替掉根节点的值
            if(!root->left) {
                return root->right;
            }
            //如果右子树为空，则用左子树的值代替掉更节点的值
            if(!root->right) {
                return root->left;
            }
            //如果左右子树都不为空
            //处理具有两个儿子的节点，一般的删除策略是用其右子树中的最小节点代替该节点的数据并递归地删除那个节点
            //successor 位于 root 的右子树中，因此大于 root 的所有左子节点；successor 是 root 的右子树中的最小节点，
            //      因此小于 root 的右子树中的其他节点。以上两点保持了新子树的有序性。
            //successor为右子树中的最小节点
            TreeNode *successor = root->right;
            while(successor->left) {
                successor = successor->left;
            }
            //删除掉successor->val代表的元素，然后将root->right代替掉(用其右子树中的最小节点代替该节点的数据并递归的删除那个节点)
            root->right = deleteNode(root->right, successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};
