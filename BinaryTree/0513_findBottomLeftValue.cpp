// created by Pi on 28/5/2021
// 找树左下角的值
// input:  2
//        / \
//       1   3
// output: 1


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
    int maxLen = INT_MIN;  // 记录最大深度
    int maxLeftValue;  // 记录左值
    void traversal(TreeNode* root, int leftLen) {  // 前序遍历，优先找到最左边的值
        if (root->left == NULL && root->right == NULL) {
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxLeftValue = root->val;
            }
            return;
        }
        if (root->left) {
            leftLen++;
            traversal(root->left, leftLen);
            leftLen--;  // 回溯
        }
        if (root->right) {
            leftLen++;
            traversal(root->right, leftLen);
            leftLen--;  // 回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxLeftValue;
    }
};


// 迭代法 层序遍历
class Solution2 {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            result = que.front()->val;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }   
        }
        return result;
    }
};

