// created by Pi on 28/5/2021
// 路径之和
// 给你二叉树的根节点root和一个表示目标和的整数targetSum，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和targetSum 。
// input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// output: true


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


// 递归+回溯 深度优先遍历 前序遍历
class Solution1 {
public:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true;  // 中
        if (!cur->left && !cur->right) return false;
        if (cur->left) {
            count -= cur->left->val;  // 递归，处理节点
            if (traversal(cur->left, count)) return true;
            count += cur->left->val;  // 回溯
        }
        if (cur->right) {
            count -= cur->right->val;  // 递归，处理节点
            if (traversal(cur->right, count)) return true;
            count += cur->right->val;  // 回溯
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};


// 迭代 利用stack 广度优先遍历
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> node = st.top();
            st.pop();
            // 如果有符合的路径，直接返回true
            if (!node.first->left && !node.first->right && targetSum == node.second) return true;
            // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->right) {
                st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
            }
            // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
            if (node.first->left) {
                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
        }
        return false;
    }
};