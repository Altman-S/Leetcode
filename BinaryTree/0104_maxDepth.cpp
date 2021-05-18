// created by Pi on 18/5/2021
// 二叉树最大深度
// input: [3,9,20,null,null,15,7]
// output: 3


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


// 层序遍历
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int result = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result++;
        }
        return result;
    }
};


// 递归
class Solution2 {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);  // 左
        int rightDepth = getDepth(node->right);  // 右
        int depth = 1 + max(leftDepth, rightDepth);  // 中
        return depth;
    }

    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};