// created by Pi on27/6/2021
// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树key对应的节点，并保证二叉搜索树的性质不变。
// 返回二叉搜索树（有可能被更新）的根节点的引用。
// input: root = [5,3,6,2,4,null,7] key = 3
// output: [5,2,6,null,4,null,7]
// https://leetcode-cn.com/problems/delete-node-in-a-bst/

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

// 递归 
class Solution1 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {  // 递归方法
        // 终止条件   
        if (root == NULL) return root;  // 第1种情况：没有遍历到key值的节点，直接返回了
        // 单层逻辑
        if (root->val == key) {
            // 第2种情况：左右孩子都为空，直接删除节点，返回NULL为根节点
            // 第3种情况：左孩子为空，右孩子不为空，返回右孩子为根节点
            if (root->left == NULL) return root->right;
            // 第4种情况：左孩子不为空，右孩子为空，返回左孩子为根节点
            else if (root->right == NULL) return root->left;
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
            // 并返回删除节点右孩子为新的根节点。
            else {
                TreeNode* cur = root->right;
                while (cur->left != NULL) {
                    cur = cur->left;  // 右孩子的最左边
                }
                cur->left = root->left;  // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;  // 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};

// 迭代
class Solution2 {
private:
    TreeNode* deleteOneNode(TreeNode* target) {  // 删除节点的函数
        if (target == NULL) return NULL;  // 左右均空
        if (target->left == NULL) return target->right;  // 左空
        if (target->right == NULL) return target->left;  // 右空
        TreeNode* cur = target->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {  // 递归方法
        if (root == NULL) return root;
        TreeNode* cur = root;
        TreeNode* pre = NULL;  // 记录父节点
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (cur->val > key) cur = cur->left;
            else if (cur->val < key) cur = cur->right;
        }
        if (pre == NULL) {
            return deleteOneNode(cur);  // 如果搜索树只有头结点
        }
        // pre要知道删除左孩子还是右孩子
        if (pre->left && pre->left->val == key) {
            pre->left = deleteOneNode(cur);
        }
        if (pre->right && pre->right->val == key) {
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};
