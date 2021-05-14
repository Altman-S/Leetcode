// created by Pi on 14/5/2021
// 二叉树的层序遍历
// input: [3,9,20,null,null,15,7],
// output: [[3],[9,20],[15,7]]


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
// 队列
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;  // 每一层的vector
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();  // 前
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);  // 左
                if (node->right) que.push(node->right);  // 右
            }
            result.push_back(vec);
        }
        return result;
    }
};
