// created by Pi on 7/6/2021
// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// output: 6
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 暴力递归 
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 结束条件
        if (root == p || root == q || root == NULL) return root;
        // 单层逻辑
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        if (left != NULL && right == NULL) return left;
        else if (left == NULL && right != NULL) return right;
        else return NULL;   
    }
};

// 递归 利用了二叉搜索树的特性
class Solution2 {
private:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        // 结束条件
        if (cur == NULL) return NULL;  // 中
        // 单层逻辑
        if (cur->val > p->val && cur->val > q->val) {  // 左
            TreeNode* left = traversal(cur->left, p, q);
            if (left != NULL) {
                return left;
            }
        }
        if (cur->val < p->val && cur->val < q->val) {
            TreeNode* right = traversal(cur->right, p, q);
            if (right != NULL) {
                return right;
            }
        }
        return cur;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};

// 迭代 最好的写法 利用二叉搜索树的特性
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return NULL;
    }
};