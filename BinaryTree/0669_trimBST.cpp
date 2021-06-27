// created by Pi on 27/6/2021
// 给你二叉搜索树的根节点root，同时给定最小边界low和最大边界high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
// 修剪树不应该改变保留在树中的元素的相对结构（如果没有被移除，原有的父代子代关系都应当保留）。可以证明，存在唯一的答案。
// input: root = [1,0,2], low = 1, high = 2
// output: [1,null,2]
// https://leetcode-cn.com/problems/trim-a-binary-search-tree/

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {  // 递归
        // 终止条件
        if (root == NULL) return root;
        // 单层逻辑
        if (root->val < low) {  // 取左节点的右子树
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if (root->val > high) {  // 取右节点的左子树
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

// 迭代
class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {  // 迭代
        if (root == NULL) return root;
        // 处理头节点，保证root节点在low和high的范围内
        while (root != NULL && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;  // 小于low往右走
            else if (root->val > high) root = root->left;  // 大于high往左走
        }
        TreeNode* cur = root;
        // 此时root已经在[low, high] 范围内，处理左孩子元素小于low的情况
        while (cur != NULL) {  // 修剪左子树
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        // 此时root已经在[low, high] 范围内，处理左孩子元素大于high的情况
        while (cur != NULL) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};