class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        }
        // queue中存储的是指针
        queue <TreeNode*> queue1, queue2;
        // 左子树用queue1
        queue1.push(p);
        // 右子树用queue2
        queue2.push(q);
        while (!queue1.empty() && !queue2.empty()) {
            // node1拿到左子树的根节点
            auto node1 = queue1.front();
            // 将左子树根删除
            queue1.pop();
            // node2拿到右子树的根节点
            auto node2 = queue2.front();
            // 将右子树根删除
            queue2.pop();
            if (node1->val != node2->val) {
                return false;
            }
            // 分别拿到左子树右子树的左右孩子
            auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
            // ^异或操作符，1^1 = 0  1^0 = 1  0^0 = 0
            // 只有left1和left2中有一个为空就执行
            if ((left1 == nullptr) ^ (left2 == nullptr)) {
                return false;
            }
            if ((right1 == nullptr) ^ (right2 == nullptr)) {
                return false;
            }
            // 如果两个节点的子节点的结构相同，则将两个节点的非空子节点分别加入两个队列，
            // 子节点加入队列时需要注意顺序，如果左右子节点都不为空，则先加入左子节点，后加入右子节点。
            if (left1 != nullptr) {
                queue1.push(left1);
            }
            if (right1 != nullptr) {
                queue1.push(right1);
            }
            if (left2 != nullptr) {
                queue2.push(left2);
            }
            if (right2 != nullptr) {
                queue2.push(right2);
            }
        }
        // 当queue1和queue2都为空时，说明俩树相同
        return queue1.empty() && queue2.empty();
    }
};
