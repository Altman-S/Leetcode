// created by Pi on 25/5/2021
// 二叉树最小深度
// input: root = [3,9,20,null,null,15,7]
// output: 2


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


// 迭代 层序遍历 
class Solution1 {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int result = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == NULL && node->right == NULL) return result + 1;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);  
            }
            result++;
        }
        return result;
    }
};


// 递归 后序遍历
class Solution2 {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);  // 左
        int rightDepth = getDepth(node->right);  // 右
        if (node->left == NULL && node->right != NULL) {
            return 1 + rightDepth;
        }
        if (node->left != NULL && node->right == NULL) {
            return 1 + leftDepth;
        }
        int depth = 1 + min(leftDepth, rightDepth);  // 中
        return depth;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};