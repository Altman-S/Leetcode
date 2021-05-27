// created by Pi on 27/5/2021
// 左子叶之和
// input:  3
//        / \
//       9  20
//         /  \
//        15   7
// output: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int leftValue = sumOfLeftLeaves(root->left);  // 左
        int rightValue = sumOfLeftLeaves(root->right);  // 右
        int midValue = 0;
        if (root->left && !root->left->left && !root->left->right) {  // 中
            midValue = root->left->val;
        }
        int sum = leftValue + rightValue +midValue;
        return sum;
    }
};


// 迭代
class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        stack<TreeNode*> st;  // 存储节点
        if (root == NULL) return 0;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left && !node->left->left && !node->left->right) {
                result += node->left->val;
            }
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return result;
    }
};