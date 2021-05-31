// created by Pi on 30/5/2021
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
// input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// output: 3
// https://mp.weixin.qq.com/s/n6Rk3nc_X3TSkhXHrVmBTQ

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归
class Solution1 {  // 前序遍历
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止条件
        if (q == root || p == root || root == NULL) return root;
        // 单层逻辑
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        if (left != NULL && right == NULL) {
            return left;
        }
        else if (left == NULL && right != NULL) {
            return right;
        }
        else {  // left == NULL && right == NULL
            return NULL;
        }
    }
};